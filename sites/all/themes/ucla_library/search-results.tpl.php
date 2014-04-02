<?php

/**
 * @file
 * Default theme implementation for displaying search results.
 *
 * This template collects each invocation of theme_search_result(). This and
 * the child template are dependent to one another sharing the markup for
 * definition lists.
 *
 * Note that modules may implement their own search type and theme function
 * completely bypassing this template.
 *
 * Available variables:
 * - $search_results: All results as it is rendered through
 *   search-result.tpl.php
 * - $module: The machine-readable name of the module (tab) being searched, such
 *   as "node" or "user".
 *
 *
 * @see template_preprocess_search_results()
 *
 * @ingroup themeable
 */
?>
<?php if ($search_results): ?>
  <h2><?php print t('Search results');?></h2>
  <ol class="search-results <?php print $module; ?>-results">
    <?php print $search_results; ?>
  </ol>
  <?php print $pager; ?>
<?php else : ?>
  <h2><?php print t('Your search yielded no results');?></h2>


<ul>
<li>Select <b>another</b> pulldown menu option (<b>'Web Site Search'</b> or <b>'Melvyl UC Catalog'</b> or <b>'UCLA Library Catalog'</b> or <b>'Research Guides'</b>) and try your search again.</li> 
<li>Try your search in the <a href="http://ucla.worldcat.org" target="_blank">Melvyl Catalog</a>
which provides information about articles, books, journals and other 
materials held by UCLA, other University of California (UC)campuses, and
libraries worldwide.</li>
<li>Try your search in the <a href="http://catalog.library.ucla.edu" target="_blank"">UCLA Library Catalog</a>
which provides information about the holdings of the UCLA Library, the 
Southern Regional Library Facility, and several specialized collections.
It Includes the titles of journals and periodicals, but it does not 
contain the titles or authors of individual articles within those 
publications.</li>
<li>Try your search in the <a href="http://guides.library.ucla.edu" target="_blank"">Research Guides</a>
which provide access to course or subject guides that provide research 
assistance and useful resources compiled by UCLA librarians. </li>
<li>Check if your spelling is correct.</li>
</ul>













  

<?php endif; ?>
