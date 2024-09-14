#________________________________________________________________________
#
# Author: Khushnood Qadir
#________________________________________________________________________
#

set ( MODULE_SOURCES
	uiapp.cc
	uimenumgr.cc
)

add_library( uiMain SHARED ${MODULE_SOURCES} )

target_include_directories( uiMain PRIVATE ${PROJECT_SOURCE_DIR}/include )
target_link_libraries( uiMain PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets uiBase )
do_export_header( uiMain )