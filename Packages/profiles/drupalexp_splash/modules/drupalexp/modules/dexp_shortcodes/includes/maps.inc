<?php

function dexp_shortcodes_maps_shortcode_info(&$shortcodes) {
    $shortcodes['maps'] = array(
        'title' => t('Maps'),
        'description' => t('Create maps shortcode'),
        'process callback' => 'dexp_shortcodes_maps',
        'tips callback' => 'dexp_shortcodes_maps_tips',
    );
    $shortcodes['marker'] = array(
        'title' => t('Map Marker'),
        'description' => t('Create map marker shortcode'),
        'process callback' => 'dexp_shortcodes_maps_marker',
    );
}

function dexp_shortcodes_maps($attrs, $text) {
	$api_key = variable_get('dexp_page_gmap_api', '');
	if(empty($api_key)){
		drupal_set_message('Gmap API is required by gmap shortcode. Click <a href="'.url('admin/drupalexp/dexp_shortcodes').'">here</a> to set it','error');
	}
	drupal_add_js('//maps.google.com/maps/api/js?key='.$api_key,'external');
	drupal_add_js(drupal_get_path('module','dexp_shortcodes').'/asset/js/dexp_gmap.js');
	drupal_add_css(drupal_get_path('module','dexp_shortcodes').'/asset/css/gmap.css');
    $attrs = shortcode_attrs(array(
        'class' => '',
        'height' => '400px',
        'type' => 'standard', //gray/color/standard
        'zoom' => '10'), $attrs);
    $attrs['content'] = $text;
    return trim(theme('dexp_shortcodes_maps', $attrs));
}

function dexp_shortcodes_maps_marker($attrs, $text){
	$attrs = shortcode_attrs(array(
        'link' => '',
        'title' => '',
        'image' => '',
        'phone' => '',
        'icon' => '',
        'latitude' => '',
        'longitude' => ''), $attrs);
    $attrs['content'] = $text;
    return "<div class=\"dexp-gmap-marker\" data-link=\"{$attrs['link']}\" data-title=\"{$attrs['title']}\" data-image=\"{$attrs['image']}\" data-phone=\"{$attrs['phone']}\" data-latitude=\"{$attrs['latitude']}\" data-longitude=\"{$attrs['longitude']}\" data-icon=\"{$attrs['icon']}\">{$text}</div>";
}

function dexp_shortcodes_maps_theme(&$themes) {
    $path = drupal_get_path('module', 'dexp_shortcodes');
    $themes['dexp_shortcodes_maps'] = array(
        'template' => 'maps',
        'path' => $path . '/theme',
        'pattern' => 'shortcode__',
        'preprocess functions' => array(
            'template_preprocess',
            'dexp_shortcodes_preprocess_shortcode_maps',
        ),
        'variables' => array(
            'class' => '',
            'type' => 'standard',
            'zoom' => '10',
            'height' => '400px',
            'content' => '',
        )
    );
}

function dexp_shortcodes_preprocess_shortcode_maps(&$vars) {
	$vars['attributes_array']['id'] = drupal_html_id('dexp_gmap_shortcode');
	$vars['classes_array'][] = drupal_html_class('dexp_gmap_shortcode');
	$vars['attributes_array']['class'] = drupal_html_class('dexp_gmap_shortcode');
	$vars['attributes_array']['style'] = "height:{$vars['height']}";
	$vars['attributes_array']['data-type'] = $vars['type'];
	$vars['attributes_array']['data-zoom'] = $vars['zoom'];
    $vars['theme_hook_suggestions'][] = 'shortcode__maps';
}

function dexp_shortcodes_maps_tips($format, $long) {
    $output = "[maps class='' type='color/standard' zoom='' height='']";
    $output .="[marker image='IMAGE_PATH' title ='TITLE' link='#' phone='PHONE' latitude='LAT' longitude='LONG' icon='ICON_PATH']ADDRESS[/marker]";
    $output .="[/maps]";
    return $output;
}