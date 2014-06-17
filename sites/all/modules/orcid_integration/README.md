CONTENTS OF THIS FILE
---------------------

 * summary
 * requirements
 * installation
 * configuration
 * troubleshooting
 * sponsors

SUMMARY
-------

ORCID provides a simple connector between Drupal and ORCID, a service to
provide unique global identifiers to researchers and their activities
(see http://orcid.org).

REQUIREMENTS
------------

Drupal Core 7.x

INSTALLATION
------------

Download and enable module.

CONFIGURATION
-------------

You need to provide the necessary configuration settings at /admin/config/services/orcid

Required:

1. Main site url (since you could work with production or sandbox)
1. Public ORCID API url (at minimum, as a fallback if the member api is not defined)

Optional:

1. ORCID Members API url
1. Client ID
1. Client Secret
1. Redirect URL

And set up the permissions (from the user permissions page)

TROUBLESHOOTING
---------------

Use the issue queue!

FAQ
---

What are the plans for the module?

Near future plans (by end of June 15, 2014) are to include a batch processing
module to provision new drupal accounts and create new ORCIDs to go for them (similarly for existing accounts).

This will be in a separate module to act as a template for others to use in
their project (or wholesale) if the needs are fully matched.

Longer term plans (which are also in short term) are to clean up the code to
make it more organized (make it OO), and to add any new features that make
sense.

SPONSORS
--------

Cherry Hill
UCLA Digital Libraries
