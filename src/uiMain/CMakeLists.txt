#________________________________________________________________________
#
# Author: Khushnood Qadir
#________________________________________________________________________
#

set ( MODULE_SOURCES
	uiapp.cc
	uiappmgr.cc
	uimenumgr.cc
)

set ( LINK_MODULES
	Qt6::Core 
	Qt6::Gui 
	Qt6::Widgets
	Basic
)

file(GLOB_RECURSE HEADER_FILES "${PROJECT_SOURCE_DIR}/include/uiMain/*.h")
add_library( uiMain SHARED ${MODULE_SOURCES} ${HEADER_FILES} )
target_include_directories( uiMain PRIVATE ${PROJECT_SOURCE_DIR}/include )
target_link_libraries( uiMain PRIVATE ${LINK_MODULES} )
do_export_header( uiMain )