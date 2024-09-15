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

set( CMAKE_ENV_VAR_PATH $ENV{CMAKE_ENV_VAR} )
set( CMAKE_PREFIX_PATH "" CACHE PATH "CMAKE Library Path" )
if ( NOT CMAKE_PREFIX_PATH AND NOT CMAKE_ENV_VAR_PATH )
	message(FATAL_ERROR "CMAKE_PREFIX_PATH is not set. Please provide path to CMake libraries. Alternatively you can define CMAKE_ENV_VAR as environment variable and set path to CMake libraries.")
elseif( CMAKE_ENV_VAR_PATH )
	set( CMAKE_PREFIX_PATH ${CMAKE_ENV_VAR_PATH} CACHE PATH "CMAKE Library Path" FORCE )
    message(WARNING "Setting CMake Prefix Path to defined environment variable, ${CMAKE_ENV_VAR_PATH}")
endif()

find_package( Qt6 COMPONENTS Core Gui Widgets REQUIRED )

include( ${CMAKE_SOURCE_DIR}/CMakeModules/doExportHeader.cmake )
include_directories( ${PROJECT_SOURCE_DIR}/include/* )

add_subdirectory( src )
