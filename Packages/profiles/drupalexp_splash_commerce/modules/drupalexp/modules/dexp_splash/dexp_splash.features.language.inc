<?php
/**
 * @file
 * dexp_splash.features.language.inc
 */

/**
 * Implements hook_locale_default_languages().
 */
function dexp_splash_locale_default_languages() {
  $languages = array();

  // Exported language: ar.
  $languages['ar'] = array(
    'language' => 'ar',
    'name' => 'Arabic',
    'native' => 'العربية',
    'direction' => 1,
    'enabled' => 1,
    'plurals' => 0,
    'formula' => '',
    'domain' => '',
    'prefix' => 'ar',
    'weight' => 0,
  );
  // Exported language: en.
  $languages['en'] = array(
    'language' => 'en',
    'name' => 'English',
    'native' => 'English',
    'direction' => 0,
    'enabled' => 1,
    'plurals' => 0,
    'formula' => '',
    'domain' => '',
    'prefix' => '',
    'weight' => 0,
  );
  return $languages;
}
