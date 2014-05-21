<?php

// Site-specific settings for www test
// Get database info from file which is excluded from repo
require_once('test.settings-db.php');

// Memcache settings
$conf['cache_backends'][] = 'sites/all/modules/memcache/memcache.inc';
$conf['cache_default_class'] = 'MemCacheDrupal';

$conf['memcache_servers'] = array(
  'test-memcached.library.ucla.edu:11211' => 'default',
);

// This was set to TRUE in main settings.php but the other 
// reverse_proxy settings were not configured.
// Leaving disabled here for now.
# $conf['reverse_proxy'] = TRUE;

