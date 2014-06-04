<?php
/**
 * Renders attached node in teaser mode.
 *
 * This module is shipped with a minimal node template.
 */
function attach_node_process($params) {
  if (($node = node_load((int)$params['nid'])) && ($node->status)) {
    $params['default_title'] = empty($params['title']) ? $node->title : $params['title'];

    if ($params['simple']) {
      if (variable_get('attach_utm_source', FALSE)) {
        $options = array('query' => array('utm_source' => 'attach'));
      }
      else {
        $options = array();
      }
      return '<span class="attach-node-' . $node->type . '">' . l($params['default_title'], 'node/' . $node->nid, $options) . '</span>';
    }
    else {
      $node->attach = $params;
      $node->build_mode = 'attach';
      return node_view($node, TRUE, FALSE, FALSE);
    }
  }
}

/**
 * Renders node in AJAX mode.
 *
 * Useful when there is non-cacheable content in attached node, like a form
 * (poll nodes).
 */
function attach_node_ajax_render($node) {
  $node->build_mode = 'attach_ajax';
  print node_view($node, TRUE, FALSE, FALSE);
}

