<?php

/**
 * @file
 * Class definition of FeedsTableProcessor.
 */

class FeedsTableProcessor extends FeedsProcessor {

  /**
   * Define a dummy entity type.
   */
  public function entityType() {
    return 'row';
  }


  protected function entityInfo() {
    $infos['label plural'] = t('rows');
    if (isset($this->config['table'])) {
      $infos['base table'] = $this->config['table'];
      $infos['entity keys']['id'] = $this->config['key'];
    }
    return $infos;
  }

  public function configDefaults() {
    $config = parent::configDefaults();
    $config['table'] = NULL;
    $config['key'] = NULL;
    return $config;
  }

  public function configForm(&$form_state) {
    $form = parent::configForm($form_state);
    $tables = db_query('SHOW TABLES');
    $options = array('' => '');
    foreach ($tables as $table) {
      $name = current((array)$table);
      $options[$name] = $name;
    }
    $form['table'] = array(
      '#type' => 'select',
      '#title' => t('Select table'),
      '#description' => t('Please select the table you want to populate.'),
      '#options' => $options,
      '#default_value' => $this->config['table'],
    );

    if (!is_null($this->config['table']) && $this->config['table'] != '') {
      $fields = db_query('DESCRIBE {' . $this->config['table'] . '}');
      $options = array('' => '');
      foreach ($fields as $field) {
        $options[$field->Field] = $field->Field;
      }
      $form['key'] = array(
        '#type' => 'select',
        '#title' => t('Select the primary key'),
        '#description' => t('Select the primary key. Will be used to rollback importation.'),
        '#options' => $options,
        '#default_value' => $this->config['key'],
      );
    }
    return $form;
  }

  /**
   * Return available mapping targets.
   */
  public function getMappingTargets() {

    if (is_null($this->config['table'])) {
      drupal_set_message(t('Please select a table first !'), 'warning');
      return;
    }

    $targets['guid'] = array(
      'name' => 'GUID',
      'description' => t('The globally unique identifier of the item. May be unique.'),
      'optional_unique' => TRUE,
    );

    $fields = db_query('DESCRIBE {' . $this->config['table'] . '}');
    foreach ($fields as $field) {
      $targets[$field->Field] = array(
        'name' => $field->Field,
        'description' => t('This is a table field of type @type.', array('@type' => $field->Type)),
        'optional_unique' => TRUE,
      );
    }

    // Let other modules expose mapping targets.
    self::loadMappers();
    feeds_alter('feeds_table_processor_targets', $targets);
    return $targets;
  }


  /**
   * Creates a new row.
   */
  protected function newEntity(FeedsSource $source) {
    return new StdClass();
  }

  public function process(FeedsSource $source, FeedsParserResult $parser_result) {
    $state = $source->state(FEEDS_PROCESS);

    while ($item = $parser_result->shiftItem()) {

      // If it exists, and we are not updating, pass onto the next item.
      $entity_id = $this->existingEntityId($source, $parser_result);
      $skip_existing = $this->config['update_existing'] == FEEDS_SKIP_EXISTING;
      if ($entity_id && $skip_existing) {
        continue;
      }

      // Do not proceed if the item exists, has not changed, and we're not
      // forcing the update.
      $hash = $this->hash($item);
      $changed = ($hash !== $this->getHash($entity_id));
      $force_update = $this->config['skip_hash_check'];
      if ($entity_id && !$changed && !$force_update) {
        continue;
      }

      // build or update

      try {

        // Build a new entity.
        if (empty($entity_id)) {
          $entity = $this->newEntity($source);
          $this->newItemInfo($entity, $source->feed_nid, $hash);
        }

        // Load an existing entity.
        else {
          $entity = $this->entityLoad($source, $entity_id);

          // The feeds_item table is always updated with the info for the most
          // recently processed entity. The only carryover is the entity_id.
          $this->newItemInfo($entity, $source->feed_nid, $hash);
          $entity->feeds_item->entity_id = $entity_id;
        }

        // Set property and field values.
        $this->map($source, $parser_result, $entity);
        $this->entityValidate($entity);

        // Allow modules to alter the entity before saving.
        module_invoke_all('feeds_presave', $source, $entity, $item);
        if (module_exists('rules')) {
          rules_invoke_event('feeds_import_'. $source->importer()->id, $entity);
        }

        // Enable modules to skip saving at all.
        if (!empty($entity->feeds_item->skip)) {
          continue;
        }

        // This will throw an exception on failure.
        $this->entitySaveAccess($entity);

        // update or save row
        if (empty($entity_id)) {
          $entity_id = $this->entitySave($entity);
        }
        else {
          $this->entityUpdate($entity, $entity_id);
        }

        $entity->feeds_item->entity_id = $entity_id;

        // feeds_item_info_insert() is normally called via hook_entity_insert()
        // but we are not working with entity.
        feeds_item_info_insert($entity, $entity_id);

        // Track progress.
        if (empty($entity_id)) {
          $state->created++;
        }
        else {
          $state->updated++;
        }


      }
      catch (Exception $e) {
        $state->failed++;
        drupal_set_message($e->getMessage(), 'warning');
        $message = $e->getMessage();
        $message .= '<h3>Original item</h3>';
        $message .= '<pre>' . var_export($item, TRUE) . '</pre>';
        $message .= '<h3>Entity</h3>';
        $message .= '<pre>' . var_export($entity, TRUE) . '</pre>';
        $source->log('import', $message, array(), WATCHDOG_ERROR);
      }

    }

    // Set messages if we're done.
    if ($source->progressImporting() != FEEDS_BATCH_COMPLETE) {
      return;
    }
    $info = $this->entityInfo();
    $tokens = array(
      '@entity' => strtolower($info['label']),
      '@entities' => strtolower($info['label plural']),
    );
    $messages = array();
    if ($state->created) {
      $messages[] = array(
       'message' => format_plural(
          $state->created,
          'Created @number @entity.',
          'Created @number @entities.',
          array('@number' => $state->created) + $tokens
        ),
      );
    }
    if ($state->updated) {
      $messages[] = array(
       'message' => format_plural(
          $state->updated,
          'Updated @number @entity.',
          'Updated @number @entities.',
          array('@number' => $state->updated) + $tokens
        ),
      );
    }
    if ($state->failed) {
      $messages[] = array(
       'message' => format_plural(
          $state->failed,
          'Failed importing @number @entity.',
          'Failed importing @number @entities.',
          array('@number' => $state->failed) + $tokens
        ),
        'level' => WATCHDOG_ERROR,
      );
    }
    if (empty($messages)) {
      $messages[] = array(
        'message' => t('There are no new @entities.', array('@entities' => strtolower($info['label plural']))),
      );
    }
    foreach ($messages as $message) {
      drupal_set_message($message['message']);
      $source->log('import', $message['message'], array(), isset($message['level']) ? $message['level'] : WATCHDOG_INFO);
    }

  }


  /**
   * Loads an existing row.
   */
  protected function entityLoad(FeedsSource $source, $id) {
    $select = db_select($this->config['table'], 't');
    $select->fields('t');
    $select->condition($this->config['key'], $id);
    return $select->execute()->fetchAssoc();
  }


  /**
   * Validates the row.
   */
  protected function entityValidate($entity) {
    // TODO
  }


  /**
   * Saves a row and returns the row id.
   */
  public function entitySave($entity) {
    $fields = (array)$entity;
    unset($fields['feeds_item']);
    $insert = db_insert($this->config['table']);
    $insert->fields($fields);
    return $insert->execute();
  }

  /**
   * Updates the row.
   */
  public function entityUpdate($entity, $entity_id) {
    $fields = (array)$entity;
    unset($fields['feeds_item']);
    $update = db_update($this->config['table']);
    $update->fields($fields);
    $update->condition($this->config['key'], $entity_id);
    $update->execute();
  }

  /**
   * Delete multiple rows.
   */
  protected function entityDeleteMultiple($ids) {
    $delete = db_delete($this->config['table']);
    $delete->condition($this->config['key'], $ids, 'IN');
    $delete->execute();

    $delete = db_delete('feeds_item');
    $delete->condition('entity_type', 'row');
    $delete->condition('entity_id', $ids, 'IN');
    $delete->execute();
  }


  public function setTargetElement(FeedsSource $source, $entity, $target_element, $value) {
    switch ($target_element) {
      case 'guid':
        $entity->feeds_item->guid = $value;
        break;
      default:
        parent::setTargetElement($source, $entity, $target_element, $value);
        break;
    }
  }

}
