<?php // $Id$

/**
 * Implementation of hook_form_alter().
 */
function webform_register_form_alter(&$form, &$form_state, $form_id) {
  // Attach my submit handler to any webforms
  if (substr($form_id, 0, 14) == 'webform_client') {
  }
}

/**
 * Implementation of _webform_edit_component().
 */
function _webform_edit_webform_register($component) {
  $form = array();
  $form['extra']['duplicate'] = array(
    '#type' => 'radios',
    '#title' => t('Handling for duplicate email addresses'),
    '#required' => TRUE,
    '#options' => array(
      'login' => t('Require the user to login'),
      'match' => t('Match the webform submission to the existing account'),
    ),
    '#description' => t('If a user enters an email that is already associated to an account, should they be asked to login, or should their account be matched to this transaction behind the scenes?  This choice is between security (are they really who they say they are?) and the convenience of accepting a submission without interruption.'),
    '#default_value' => $component['extra']['duplicate'],
  );
  return $form;
}

/**
 * Implementation of _webform_render_component().
 */
function _webform_render_webform_register($component, $value = NULL, $filter = TRUE) {
  global $user;

  $element = array(
    '#element_validate' => array('webform_register_validate'),
    '#required'  => $component['mandatory'],
    '#component' => $component,
    '#tree'      => TRUE,
  );

  $form_key = $component['form_key'];

  // The user is already authenticated.
  if ($user->uid) {
    $element[$form_key]['uid'] = array(
      '#type' => 'value', 
      '#value' => $user->uid,
    );
  }

  // The user is anonymous. Show the login / register component.
  else {

    // Retreive the user registration form for embedding.
    $register_state = array();
    $register = drupal_retrieve_form('user_register', $register_state);
    drupal_prepare_form('user_register', $register, $register_state);

    foreach ($register as $key => $value) {
      $exclude = array('form_id', '#build_id', '#id', '#method', '#action', 'submit');
      if (!in_array($key, $exclude)) {
        // Add the registration form's field to the element.
        $element[$form_key][$key] = $value;

        if ($key[0] == '#') {
          // If it starts with #, also add it to a $form element for later use.
          $form_settings[$key] = $value;
        }
        else {
          // Set #parents so that the value can be located by webform.
          $element[$form_key][$key]['#parents'] = array(
            'submitted', $form_key, $key
          );
        }

        // TODO not working.
        if (!$element['#required'] && is_array($element[$form_key][$key])) {
          unset($element[$form_key][$key]['#required']);
        }
      }
    }
    $element[$form_key]['form_settings'] = array(
      '#type' => 'value',
      '#value' => $form_settings,
      '#parents' => array('submitted', $form_key, 'form_settings'),
    );
    $element[$form_key]['form_state'] = array(
      '#type' => 'value',
      '#value' => $register_state,
      '#parents' => array('submitted', $form_key, 'form_state'),
    );
  }

  return $element;
}

/**
 * An element_validate callback for the webform_register component.
 */
function webform_register_validate($element, &$form_state) {
  $form_key = $element['#component']['form_key'];

  // Has the element been populated at all?
  $submitted = FALSE;
  foreach (element_children($element[$form_key]) as $key) {
    if (!empty($element[$form_key][$key]['#value'])) {
      $submitted = TRUE;
    }
  }

  // If it's either submitted or required, validate it!
  if ($submitted || $element['#required']) {
    // Put the webform_register values where the validate handler expects them.
    $register_state = $form_state;
    $values = $form_state['values']['submitted'][$form_key];

    if (is_array($values['form_state'])) {
      $register_state = array_merge($register_state, $values['form_state']);
    }

    if (is_array($values)) {
      $register_state['values'] = array_merge($register_state['values'], $values);
    }

    // Do some validation of my own: if the email address is already
    // registered, rely on administrative settings to match the submission.
    $unique = $validate = TRUE;
    if($mail = $register_state['values']['mail']) {
      if ($uid = db_result(db_query("SELECT uid FROM {users} 
        WHERE mail = '%s'", $mail))) {

        if ($element['#component']['extra']['duplicate'] == 'match') {
          $register_state['uid'] = $uid;
          $validate = FALSE;
        }
      }
    }

    // Just call the normal validate handlers.
    if ($validate) {
      form_execute_handlers('validate', $element[$form_key], $register_state);
    }

    // Copy $register_state values into $form_state if they weren't already set.
    // This helps for modules that expect $form_state for #pre_render, etc.
    $form_state['values']['submitted'][$form_key]['form_state'] = $register_state;
  }
}

/**
 * Implementation of _webform_submit_component().
 */
function _webform_submit_webform_register($component, $value) {
  // There was already a UID.  Nothing to see here!
  if (isset($value['uid'])) return $value;

  // Retrieve the $form settings that were stashed in the value.
  $register = $value['form_settings'];
  unset($value['form_settings']);

  // Retrieve the component-specific $form_state we've been toting around.
  $register_state = $value['form_state'];
  unset($value['form_state']);
  $register_state['submitted'] = TRUE;

  // If the uid was matched already, so use that value.
  if (isset($register_state['uid'])) {
    return array('uid' => $register_state['uid']);
  }

  // Execute all of the user_registration form's submit handlers.
  form_execute_handlers('submit', $register, $register_state);

  // Save the newly-generated uid as the value.
  $value = array('uid' => $register_state['user']->uid);

  return $value;
}

function webform_register_webform_submission_presave($node, &$submission) {
  if (!$submission->uid) {
    // Set the submission's uid as the newly-created user.
    foreach ($node->webform['components'] as $cid => $component) {
      if ($component['type'] == 'webform_register') {
        $submission->uid = $submission->data[$cid]['value']['uid'];
      }
    }
  }
}

/**
 * Implementation of _webform_display_component().
 */
function _webform_display_webform_register($component, $value, $format = 'html') {
  //TODO
  return array(
    '#title' => $component['name'],
    '#weight' => $component['weight'],
    '#theme' => 'webform_display_webform_register',
    '#theme_wrappers' => $format == 'html' ? array('webform_element') : array('w
ebform_element_text'),
    '#post_render' => array('webform_element_wrapper'),
    '#field_prefix' => $component['extra']['field_prefix'],
    '#field_suffix' => $component['extra']['field_suffix'],
    '#component' => $component,
    '#format' => $format,
    '#value' => isset($value[0]) ? $value[0] : '',
  );
}

/**
 * Implementation of _webform_analysis_component().
 */
function _webform_analysis_webform_register($component, $sids = array()) {
}

/**
 * Implementation of _webform_table_component().
 */
function _webform_table_webform_register($component, $value) {
  return check_plain(empty($value[0]) ? '' : $value[0]);
}

/**
 * Implementation of _webform_csv_headers_component().
 */
function _webform_csv_headers_webform_register($component, $export_options) {
  $header = array();
  $header[0] = '';
  $header[1] = '';
  $header[2] = $component['name'];
  return $header;
}

/**
 * Implementation of _webform_csv_data_component().
 */
function _webform_csv_data_webform_register($component, $export_options, $value) {
  return !isset($value[0]) ? '' : $value[0];
}
