#________________________________________________________________________
#
# Author: Khushnood Qadir
#________________________________________________________________________
#

add_executable( VSProj main.cc )

target_include_directories( VSProj PRIVATE ${PROJECT_SOURCE_DIR}/include )

target_link_libraries( VSProj PUBLIC Qt6::Core Qt6::Gui Qt6::Widgets uiBase )
