#________________________________________________________________________
#
# Author: Khushnood Qadir
#________________________________________________________________________
#

set ( MODULE_SOURCES
	uiopenprojdlg.cc
)

set ( LINK_MODULES
	Qt6::Core 
	Qt6::Gui 
	Qt6::Widgets
	Basic
)

file(GLOB_RECURSE HEADER_FILES "${PROJECT_SOURCE_DIR}/include/uiComps/*.h")
add_library( uiComps SHARED ${MODULE_SOURCES} ${HEADER_FILES} )
target_include_directories( uiComps PRIVATE ${PROJECT_SOURCE_DIR}/include )
target_link_libraries( uiComps PRIVATE ${LINK_MODULES} )
do_export_header( uiComps )