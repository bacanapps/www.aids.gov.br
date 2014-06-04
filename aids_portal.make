; ----------------
; Generated makefile from http://drushmake.me
; Permanent URL: http://drushmake.me/file.php?token=a1324f68ffa2
; ----------------
;
; This is a working makefile - try it! Any line starting with a `;` is a comment.
  
; Core version
; ------------
; Each makefile should begin by declaring the core version of Drupal that all
; projects should be compatible with.
  
core = 6.x
  
; API version
; ------------
; Every makefile needs to declare its Drush Make API version. This version of
; drush make uses API version `2`.
  
api = 2
  
; Core project
; ------------
; In order for your makefile to generate a full Drupal site, you must include
; a core project. This is usually Drupal core, but you can also specify
; alternative core projects like Pressflow. Note that makefiles included with
; install profiles *should not* include a core project.
  
; Drupal 6.x core:
projects[drupal][version] = 6.x

  
  
; Modules
; --------
projects[admin_menu][version] = 1.8
projects[admin_menu][type] = "module"
projects[cck][version] = 2.9
projects[cck][type] = "module"
projects[content_taxonomy][version] = 1.0-rc2
projects[content_taxonomy][type] = "module"
projects[email][version] = 1.4
projects[email][type] = "module"
projects[filefield][version] = 3.12
projects[filefield][type] = "module"
projects[imagefield][version] = 3.11
projects[imagefield][type] = "module"
projects[link][version] = 2.11
projects[link][type] = "module"
projects[ctools][version] = 1.11
projects[ctools][type] = "module"
projects[date][version] = 2.10
projects[date][type] = "module"
projects[devel][version] = 1.28
projects[devel][type] = "module"
projects[image][version] = 1.2
projects[image][type] = "module"
projects[imagecache_actions][version] = 1.9
projects[imagecache_actions][type] = "module"
projects[imageapi][version] = 1.10
projects[imageapi][type] = "module"
projects[imagecache][version] = 2.0-rc1
projects[imagecache][type] = "module"
projects[gmap][version] = 2.0-beta5
projects[gmap][type] = "module"
projects[location][version] = 3.3
projects[location][type] = "module"
projects[emfield][version] = 2.6
projects[emfield][type] = "module"
projects[i18n][version] = 1.10
projects[i18n][type] = "module"
projects[advanced_help][version] = 1.2
projects[advanced_help][type] = "module"
projects[auto_nodetitle][version] = 1.2
projects[auto_nodetitle][type] = "module"
projects[backup_migrate][version] = 2.8
projects[backup_migrate][type] = "module"
projects[better_formats][version] = 1.2
projects[better_formats][type] = "module"
projects[dhtml_menu][version] = 3.5
projects[dhtml_menu][type] = "module"
projects[globalredirect][version] = 1.5
projects[globalredirect][type] = "module"
projects[google_analytics][version] = 3.6
projects[google_analytics][type] = "module"
projects[imce][version] = 2.7
projects[imce][type] = "module"
projects[logintoboggan][version] = 1.10
projects[logintoboggan][type] = "module"
projects[menu_block][version] = 2.4
projects[menu_block][type] = "module"
projects[menu_breadcrumb][version] = 1.4
projects[menu_breadcrumb][type] = "module"
projects[pathauto][version] = 1.6
projects[pathauto][type] = "module"
projects[path_redirect][version] = 1.0-rc2
projects[path_redirect][type] = "module"
projects[rules][version] = 1.5
projects[rules][type] = "module"
projects[token][version] = 1.19
projects[token][type] = "module"
projects[panels][version] = 3.10
projects[panels][type] = "module"
projects[captcha][version] = 2.5
projects[captcha][type] = "module"
projects[ckeditor][version] = 1.14
projects[ckeditor][type] = "module"
projects[jquery_ui][version] = 1.5
projects[jquery_ui][type] = "module"
projects[views][version] = 2.16
projects[views][type] = "module"
projects[views_bonus][version] = 1.1
projects[views_bonus][type] = "module"
projects[views_bulk_operations][version] = 1.16
projects[views_bulk_operations][type] = "module"
projects[webform][version] = 3.20
projects[webform][type] = "module"
projects[] = accents
projects[] = action_email_role
projects[] = advanced_blog
projects[] = advancedbookblocks
projects[] = attach
projects[] = book_helper
projects[] = book_search
projects[] = cache_browser
projects[] = cmf
projects[] = conditional_fields
projects[] = contact_google_analytics
projects[] = custom_pub
projects[] = ed_readmore
projects[] = event
projects[] = event_views
projects[] = filefield_paths
projects[] = filefield_sources
projects[] = flowplayer
projects[] = format_number
projects[] = iframe
projects[] = imagefield_extended
projects[] = imagefield_import
projects[] = imce_mkdir
projects[] = insert
projects[] = instant_search
projects[] = javascript_aggregator
projects[] = jcarousel
projects[] = jquerymenu
projects[] = lang_dropdown
projects[] = libraries
projects[] = masquerade
projects[] = menu_node
projects[] = module_grants
projects[] = node_clone
projects[] = node_export
projects[] = nodereference_url
projects[] = page_theme
projects[] = phpmailer
projects[] = revisioning
projects[] = scroll_to_top
projects[] = search_block
projects[] = semiclean
projects[] = strongarm
projects[] = synonyms
projects[] = tooltips
projects[] = triggerunlock
projects[] = upload_preview
projects[] = uploadpath
projects[] = views_attach
projects[] = views_bulk_operations
projects[] = views_data_export
projects[] = watcher
projects[] = webform_conditional
projects[] = webform_register
projects[] = webform_registration
projects[] = webform_table_element
projects[] = webform_validation
projects[] = workflow

  

; Themes
; --------

  
  
; Libraries
; ---------
libraries[jquery][download][type] = "file"
libraries[jquery][download][url] = "https://ajax.googleapis.com/ajax/libs/jquery/1.7.2/jquery.min.js"
libraries[jqueryui][download][type] = "file"
libraries[jqueryui][download][url] = "https://ajax.googleapis.com/ajax/libs/jqueryui/1.8.18/jquery-ui.min.js"


