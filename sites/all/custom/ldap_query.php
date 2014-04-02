<?php
$server = 'ldap.ucla.edu';
$basedn = 'ou=Faculty and Staff,ou=person,dc=ldap,dc=ucla,dc=edu';

// These should be set by caller, which does an include() of this file
// But just in case, define with any defaults required.
if (! isset($include_term_string)) {$include_term_string = 'lib';}
if (! isset($exclude_term_string)) {$exclude_term_string = '';}

$include_filter = '';
if (strlen($include_term_string) > 0) {
	$include_terms = explode(" ", $include_term_string);
	foreach ($include_terms as $term) {
		$include_filter .= '(partialdepartment=' . $term . ') ';
	}
	$include_filter = '&' . $include_filter;
}

$exclude_filter = '';
if (strlen($exclude_term_string) > 0) {
	$exclude_terms = explode(" ", $exclude_term_string);
	foreach ($exclude_terms as $term) {
		$exclude_filter .= '(partialdepartment=' . $term . ') ';
	}
	$exclude_filter = '(!(|' . $exclude_filter . '))';
}

$filter = '(' . $include_filter . $exclude_filter . ')';
echo $filter;

if (!($connect = ldap_connect($server))) die ("Could not connect to LDAP server $server");
if (!($bind = ldap_bind($connect, "", ""))) die ("Could not bind to $basedn");

$results = ldap_search($connect, $basedn, $filter, array('cn', 'admcode', 'department', 'mail', 'postalcode', 'telephonenumber', 'title', 'uclapostaladdress'),0,500);
//$results = ldap_search($connect, $basedn, $filter);

$entries = ldap_get_entries($connect, $results);

$count = $entries["count"];
//echo '<p>Found ' . $count . ' entrie(s)</p>';

for ($i=0; $i < $entries["count"]; $i++) {
	$name = (isset($entries[$i]["cn"][0]) ? $entries[$i]["cn"][0] : '');
	$admcode = (isset($entries[$i]["admcode"][0]) ? $entries[$i]["admcode"][0] : '');
	$dept = (isset($entries[$i]["department"][0]) ? $entries[$i]["department"][0] : '');
	$mail = (isset($entries[$i]["mail"][0]) ? $entries[$i]["mail"][0] : '');
	$postalcode = (isset($entries[$i]["postalcode"][0]) ? $entries[$i]["postalcode"][0] : '');
	$telephonenumber = (isset($entries[$i]["telephonenumber"][0]) ? $entries[$i]["telephonenumber"][0] : '');
	$title = (isset($entries[$i]["title"][0]) ? $entries[$i]["title"][0] : '');
	$uclapostaladdress = (isset($entries[$i]["uclapostaladdress"][0]) ? $entries[$i]["uclapostaladdress"][0] : '');

	// Show data as html definition list, as used on current site
	echo '<dl>';
	echo '<dt>' . $name . '</dt>';
	echo '<dd>Title:&nbsp;' . $title . '</dd>';
	echo '<dd>Department:&nbsp;' . $dept . '</dd>';
	echo '<dd>Address:&nbsp;' . $uclapostaladdress . '</dd>';
	echo '<dd>Mail code:&nbsp;' . $postalcode . '</dd>';
	echo '<dd>Adm. code:&nbsp;' . $admcode . '</dd>';
	echo '<dd>Phone:&nbsp;' . $telephonenumber . '</dd>';
	echo '<dd><a href="/test-email-contact-form?target_address=akohler@library.ucla.edu"><img src="http://www.library.ucla.edu/images/i_mail_blk.gif" alt="Send email message" border="0" width="13" height="12" vspace="4"></a></dd>';
	//<dd><a href="/about/1244.cfm?qs=gore%20robert%20j%2E%20c%2E"><img src="/images/i_mail_blk.gif" alt="Send email message" border="0" width="13" height="12" vspace="4"></a></dd>
	echo "</dl>";
}

ldap_unbind($connect);

?>
