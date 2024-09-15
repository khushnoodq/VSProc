#________________________________________________________________________
#
# Author: Khushnood Qadir
#________________________________________________________________________
#

cmake_minimum_required( VERSION 3.0.0 )

project( VSproj VERSION 1.0.0 )

set( CMAKE_INCLUDE_CURRENT_DIR ON )
set( CMAKE_AUTOMOC ON )
set( CMAKE_AUTORCC ON )
set( CMAKE_AUTOUIC ON )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED True )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin )

set( CMAKE_PREFIX_PATH "" CACHE PATH "CMAKE Library Path" )
if ( NOT CMAKE_PREFIX_PATH )
    set( CMAKE_LIB_VAR_PATH $ENV{CMAKE_LIB_PATH} )
    if ( CMAKE_LIB_VAR_PATH )
	set( CMAKE_PREFIX_PATH ${CMAKE_LIB_VAR_PATH} CACHE PATH "CMAKE Library Path" FORCE )
	message(WARNING "Setting CMake Prefix Path to defined environment variable, ${CMAKE_LIB_VAR_PATH}")
    else()
	message(FATAL_ERROR "CMAKE_PREFIX_PATH is not set. Please provide path to CMake libraries. Alternatively you can define CMAKE_LIB_PATH as environment variable and set path to CMake libraries.")
    endif()
endif()

find_package( Qt6 COMPONENTS Core Gui Widgets REQUIRED )

include( ${CMAKE_SOURCE_DIR}/CMakeModules/doExportHeader.cmake )
include_directories( ${PROJECT_SOURCE_DIR}/include/* )

add_subdirectory( src )
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)