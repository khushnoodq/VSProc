#________________________________________________________________________
#
# Author: Khushnood Qadir
#________________________________________________________________________
#

function( do_export_header MODULE_NAME )
    if( NOT MODULE_NAME )
        message( FATAL_ERROR "MODULE_NAME argument is required" )
    endif()

    string( TOLOWER ${MODULE_NAME} MODULE_NAME_LOWER )
    message( ${MODULE_NAME_LOWER} )
    include( GenerateExportHeader )
    generate_export_header( ${MODULE_NAME}
        BASE_NAME ${MODULE_NAME}
        EXPORT_MACRO_NAME Export_${MODULE_NAME}
        EXPORT_FILE_NAME ${CMAKE_CURRENT_BINARY_DIR}/${MODULE_NAME_LOWER}mod.h
    )

    message( ${CMAKE_CURRENT_BINARY_DIR}/${MODULE_NAME_LOWER}mod.h )

    target_include_directories( ${MODULE_NAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR} )
endfunction()
