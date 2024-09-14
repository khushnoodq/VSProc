/*+
________________________________________________________________________

	Author: Khushnood Qadir
________________________________________________________________________

-*/

#include "uiMain/uimenumgr.h"

#include <QMenuBar>

uiMenuMgr::uiMenuMgr( uiMainApp* app )
	: appl_( *app )
{
	auto* mb = appl_.menuBar();
	filemenu_ = mb->addMenu( "File" );
	procmenu_ = mb->addMenu( "Processing" );
	utilsmenu_ = mb->addMenu( "Utilities" );
	helpmenu_ = mb->addMenu( "Help" );
}


uiMenuMgr::~uiMenuMgr()
{}