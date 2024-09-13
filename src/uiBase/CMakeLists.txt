#________________________________________________________________________
#
# Author: Khushnood Qadir
#________________________________________________________________________
#

set ( MODULE_SOURCES
	uimainwin.cc
)

add_library( uiBase SHARED ${MODULE_SOURCES} )

target_include_directories( uiBase PRIVATE ${PROJECT_SOURCE_DIR}/include )
target_link_libraries( uiBase PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets )
do_export_header( uiBase )
source_group( "Header Files" FILES ${HEADER_FILES} )

set_target_properties( uiBase PROPERTIES AUTOMOC TRUE )