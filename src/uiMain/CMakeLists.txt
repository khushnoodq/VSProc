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

file(GLOB_RECURSE HEADER_FILES "${PROJECT_SOURCE_DIR}/include/uiMain/*.h")

#Adding Header files to library, this reflect the header file for this module in group
add_library( uiMain SHARED ${MODULE_SOURCES} ${HEADER_FILES} )

target_include_directories( uiMain PRIVATE ${PROJECT_SOURCE_DIR}/include )

target_link_libraries( uiMain PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets )
do_export_header( uiMain )