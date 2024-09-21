#________________________________________________________________________
#
# Author: Khushnood Qadir
#________________________________________________________________________
#

set ( MODULE_SOURCES
	commonstrs.cc
	dBManager.cc
	projectInfo.cc
	seisDBManager.cc
	wellDBManager.cc	
)

set ( LINK_MODULES
	Qt6::Core
	Qt6::Sql
)

file(GLOB_RECURSE HEADER_FILES "${PROJECT_SOURCE_DIR}/include/Basic/*.h")
add_library( Basic SHARED ${MODULE_SOURCES} ${HEADER_FILES} )
target_include_directories( Basic PRIVATE ${PROJECT_SOURCE_DIR}/include )
target_link_libraries( Basic PRIVATE ${LINK_MODULES} )
do_export_header( Basic )
