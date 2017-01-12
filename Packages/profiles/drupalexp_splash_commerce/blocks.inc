<?php
function drupalexp_profile_blocks(&$blocks,$default_theme){
	$blocks[] = array(
			'title' => '<none>',
      'module' => 'dexp_menu',
      'delta' => 'dexp_menu_block_1',
      'theme' => $default_theme,
      'status' => 1,
      'weight' => 0,
      'region' => 'navigation',
      'pages' => '',
      'cache' => -1,
    );
	$blocks[] = array(
      'title' => '<none>',
      'module' => 'system',
      'delta' => 'user-menu',
      'theme' => $default_theme,
      'status' => 1,
      'weight' => -49,
      'region' => 'top_right',
      'pages' => '',
      'cache' => -1,
    );
	$blocks[] = array(
			'title' => '<none>',
      'module' => 'dexp_popup_login',
      'delta' => 'bootstrap-login',
      'theme' => $default_theme,
      'status' => 1,
      'weight' => -50,
      'region' => 'top_right',
      'pages' => '',
      'cache' => -1,
    );
	$blocks[] =	array(
			'title' => '<none>',
      'module' => 'dexp_page_elements',
      'delta' => 'dexp_page_elements_breadcrumb',
      'theme' => $default_theme,
      'status' => 1,
      'weight' => -21,
      'region' => 'pagetitle',
      'pages' => '',
      'cache' => -1,
    );
	$blocks[] = array(
			'title' => '<none>',
      'module' => 'dexp_page_elements',
      'delta' => 'dexp_page_elements_page_title',
      'theme' => $default_theme,
      'status' => 1,
      'weight' => -22,
      'region' => 'pagetitle',
      'pages' => '',
      'cache' => -1,
    );
		$blocks[] = array(
			'title' => '<none>',
      'module' => 'views',
      'delta' => 'simple_shopping_cart-block',
      'theme' => $default_theme,
      'status' => 1,
      'weight' => -22,
      'region' => 'top_right',
      'pages' => '',
      'cache' => -1,
    );
	$blocks[] = array(
			'title' => '<none>',
      'module' => 'system',
      'delta' => 'main',
      'theme' => $default_theme,
      'status' => 1,
      'weight' => 0,
      'region' => 'content',
      'pages' => '',
      'cache' => -1,
    );
  $blocks[] = array(
			'title' => '<none>',
      'module' => 'search',
      'delta' => 'form',
      'theme' => $default_theme,
      'status' => 1,
      'weight' => -1,
      'region' => 'search',
      'pages' => '',
      'cache' => -1,
    );
   $blocks[] = array(
			'title' => '<none>',
      'module' => 'system',
      'delta' => 'powered-by',
      'theme' => $default_theme,
      'status' => 1,
      'weight' => 10,
      'region' => 'copyright',
      'pages' => '',
      'cache' => -1,
    );
}