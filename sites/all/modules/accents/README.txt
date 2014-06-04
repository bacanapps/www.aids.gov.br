/* $Id: README.txt,v 1.3 2010/06/15 00:12:12 jimbullington Exp $*/

accents is simple module that removes accents from words to provide better
search results. For example "á â Å ã" all become "a".

Installation
------------

Copy accents.module to your module directory and then enable on the admin 
modules page.

Re-index your search.

In the Drupal 6.x version, an administrative setting was added to allow
the module to remove accents during search indexing.  The setting is FALSE 
by default and will generally not be necessary since the Drupal 6.x search 
module handles database collation properly.  If search results for accented 
characters are not being handled correctly, this setting can be enabled to 
have the module remove accented characters during a re-index.  Search must 
be re-indexed after changing this setting in order to test the results.

Credits
-------

The _accents_remove_accents and _accents_seems_utf8 do all the work and were
taken from http://trac.wordpress.org/browser/trunk/wp-includes/formatting.php

Issues
------
As pointed out in #2 at this comment, http://drupal.org/node/78259#comment-124541, 
some search results may be deceiving.



