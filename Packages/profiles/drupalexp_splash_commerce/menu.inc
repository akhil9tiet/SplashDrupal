<?php
function drupalexp_profile_menu_items(&$items){
	$items[] = array(
    'link_title' => st('Portfolio'),
    'link_path' => 'portfolio',
    'menu_name' => 'main-menu',
		'weight' => 1,
  );
	$items[] = array(
    'link_title' => st('Blog'),
    'link_path' => 'blog-large',
    'menu_name' => 'main-menu',
		'weight' => 2,
  );
	$items[] = array(
    'link_title' => st('Shop'),
    'link_path' => 'products-fullwidth',
    'menu_name' => 'main-menu',
		'weight' => 2,
  );
}