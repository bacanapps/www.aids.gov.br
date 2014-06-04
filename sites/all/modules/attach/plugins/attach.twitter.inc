<?php
/**
 * Embed Twitter status.
 */
function attach_twitter_process($params) {
  $url = url('https://api.twitter.com/1/statuses/oembed.json', array(
    'query' => array(
      'id' => $params['id'],
      'lang' => $params['lang'],
      'width' => $params['width'],
      'height' => $params['height'],
    ),
  ));
  $result = drupal_http_request($url);
  if ($result->code == '200') {
    $data = json_decode($result->data, TRUE);
    return $data['html'];
  }
}

