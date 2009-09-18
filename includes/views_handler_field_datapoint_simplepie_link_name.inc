<?php
// $Id: views_handler_field_node.inc,v 1.1 2008/09/03 19:21:29 merlinofchaos Exp $
/**
 * @file
 * Contains the basic 'node' field handler.
 */

/**
 * Field handler to provide simple renderer that allows linking to a datapoint simplepie.
 */
class views_handler_field_datapoint_simplepie_link_name extends views_handler_field {
  function option_definition() {
    $options = parent::option_definition();

    $options['external_link'] = array('default' => TRUE);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['external_link'] = array(
      '#title' => t('Open in new window'),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['external_link']),
    );
  }

  function query() {
    parent::query();
    $this->aliases['name'] = $this->query->add_field('datapoint', 'name');
  }

  function render($values) {
    $options = array('absolute' => TRUE);

    if (!empty($this->options['external_link'])) {
      $options['attributes'] = array('target' => '_blank');
    }

    return l($values->{$this->aliases['name']}, $values->{$this->field_alias}, $options);
  }
}
