<?php
/**
 * Implements hook_form_FORM_ID_alter().
 *
 * @param $form
 *   The form.
 * @param $form_state
 *   The form state.
 */
function professional_theme_form_system_theme_settings_alter(&$form, &$form_state) {

  $form['prof_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Professional Theme Settings'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );
  $form['prof_settings']['breadcrumbs'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show breadcrumbs in a page'),
    '#default_value' => theme_get_setting('breadcrumbs','professional_theme'),
    '#description'   => t("Check this option to show breadcrumbs in page. Uncheck to hide."),
  );
  $form['prof_settings']['display_theme_credit'] = array(
  	'#type' => 'checkbox',
  	'#title' => t('Remove Theme Credit from the footer'),
  	'#default_value' => theme_get_setting('display_theme_credit', 'professional_theme'),
  	'#description' => t("check this option to remove the theme credit from the footer"),
  );
    $form['prof_settings']['copywrite_information'] = array(
    '#type' => 'fieldset',
    '#title' => t('Copywrite Information'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['prof_settings']['copywrite_information']['remove_copywrite'] = array(
  	'#type' => 'checkbox',
  	'#title' => t('Remove Copywrite from the footer'),
  	'#default_value' => theme_get_setting('remove_copywrite', 'professional_theme'),
  	'#description' => t("check this option to remove the copywrite information from the footer"),
  );
  $form['prof_settings']['copywrite_information']['copywrite_holder'] = array(
  	'#type' => 'textfield',
    '#title' => t('Copywrite Holder'),
    '#default_value' => theme_get_setting('copywrite_holder','professional_theme'),
    '#description' => 'Name the Copywrite holder of the site that will be displayed in the footer'
  );
  $form['prof_settings']['slideshow'] = array(
    '#type' => 'fieldset',
    '#title' => t('Front Page Slideshow'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['prof_settings']['slideshow']['slideshow_display'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show slideshow'),
    '#default_value' => theme_get_setting('slideshow_display','professional_theme'),
    '#description'   => t("Check this option to show Slideshow in front page. Uncheck to hide."),
  );
  $form['prof_settings']['slideshow']['slide'] = array(
  	'#markup' => t('You can change the description and URL of each slide in the following Slide Setting fieldsets.'),
  );
  $form['prof_settings']['slideshow']['slide1'] = array(
    '#type' => 'fieldset',
    '#title' => t('Slide 1'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['prof_settings']['slideshow']['slide1']['slide1_head'] = array(
    '#type' => 'textfield',
    '#title' => t('Slide Headline'),
    '#default_value' => theme_get_setting('slide1_head','professional_theme'),
  );

  $form['prof_settings']['slideshow']['slide1']['slide1_image_url'] = array(
    '#type' => 'textarea',
    '#title' => t('Image URL'),
  );
  $form['prof_settings']['slideshow']['slide1']['slide1_desc'] = array(
    '#type' => 'textarea',
    '#title' => t('Slide Description'),
    '#default_value' => theme_get_setting('slide1_desc','professional_theme'),
  );
  $form['prof_settings']['slideshow']['slide1']['slide1_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Slide URL'),
    '#default_value' => theme_get_setting('slide1_url','professional_theme'),
  );
 $form['prof_settings']['slideshow']['slide1']['slide_alt'] = array(
    '#type' => 'textfield',
    '#title' => t('Image Alt Text'),
    '#default_value' => theme_get_setting('slide_alt','professional_theme'),
);
  $form['prof_settings']['slideshow']['slide2'] = array(
    '#type' => 'fieldset',
    '#title' => t('Slide 2'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['prof_settings']['slideshow']['slide2']['slide2_head'] = array(
    '#type' => 'textfield',
    '#title' => t('Slide Headline'),
    '#default_value' => theme_get_setting('slide2_head','professional_theme'),
  );
  $form['prof_settings']['slideshow']['slide2']['slide2_image_url'] = array(
    '#type' => 'textarea',
    '#title' => t('Image URL'),
  );

  $form['prof_settings']['slideshow']['slide2']['slide2_desc'] = array(
    '#type' => 'textarea',
    '#title' => t('Slide Description'),
    '#default_value' => theme_get_setting('slide2_desc','professional_theme'),
  );
  $form['prof_settings']['slideshow']['slide2']['slide2_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Slide URL'),
    '#default_value' => theme_get_setting('slide2_url','professional_theme'),
  );
 $form['prof_settings']['slideshow']['slide2']['slide2_alt'] = array(
    '#type' => 'textfield',
    '#title' => t('Image Alt Text'),
    '#default_value' => theme_get_setting('slide_alt2','professional_theme'),
);
  $form['prof_settings']['slideshow']['slide3'] = array(
    '#type' => 'fieldset',
    '#title' => t('Slide 3'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['prof_settings']['slideshow']['slide3']['slide3_head'] = array(
    '#type' => 'textfield',
    '#title' => t('Slide Headline'),
    '#default_value' => theme_get_setting('slide3_head','professional_theme'),
  );
  $form['prof_settings']['slideshow']['slide3']['slide3_image_url'] = array(
    '#type' => 'textarea',
    '#title' => t('Image URL'),
  );
  $form['prof_settings']['slideshow']['slide3']['slide3_desc'] = array(
    '#type' => 'textarea',
    '#title' => t('Slide Description'),
    '#default_value' => theme_get_setting('slide3_desc','professional_theme'),
  );
  $form['prof_settings']['slideshow']['slide3']['slide3_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Slide URL'),
    '#default_value' => theme_get_setting('slide3_url','professional_theme'),
  ); 
  $form['prof_settings']['slideshow']['slide3']['slide3_alt'] = array(
    '#type' => 'textfield',
    '#title' => t('Image Alt Text'),
    '#default_value' => theme_get_setting('slide_alt3','professional_theme'),
);
  $form['prof_settings']['slideshow']['slideimage'] = array(
    '#markup' => t('To change the Slide Images, Replace the slide-image-1.jpg, slide-image-2.jpg and slide-image-3.jpg in the images folder of the Professional theme folder.'),
  );
}
