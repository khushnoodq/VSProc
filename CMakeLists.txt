cmake_minimum_required( VERSION 3.0.0 )

project( VSproj VERSION 1.0.0 )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED True )

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin )

set( CMAKE_PREFIX_PATH "D:/dev/VSP_proc/appman/qt/6.5.3/msvc2019_64" )

# Find Qt packages
find_package( Qt6 COMPONENTS Core Gui Widgets REQUIRED )

# Include directories
include_directories( ${PROJECT_SOURCE_DIR}/include/* )

add_subdirectory( src )
