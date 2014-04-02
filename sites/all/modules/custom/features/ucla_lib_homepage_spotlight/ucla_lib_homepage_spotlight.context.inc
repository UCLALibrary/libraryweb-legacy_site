<?php
/**
 * @file
 * ucla_lib_homepage_spotlight.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function ucla_lib_homepage_spotlight_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'homepage_spotlight';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-homepage_feature-block_1' => array(
          'module' => 'views',
          'delta' => 'homepage_feature-block_1',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['homepage_spotlight'] = $context;

  return $export;
}
