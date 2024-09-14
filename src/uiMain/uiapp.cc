/*+
________________________________________________________________________

	Author: Khushnood Qadir
________________________________________________________________________

-*/

#include "uiMain/uiapp.h"
#include "uiMain/uimenumgr.h"

uiMainApp& AppMainWin()
{
    mDefineStaticLocalObject( uiMainApp, instance, );
    return instance;
}


uiMainApp::uiMainApp()
	: QMainWindow( nullptr )
{
	setWindowTitle( "VSProc" );
	menumgr_ = new uiMenuMgr( this );
}


uiMainApp::~uiMainApp()
{
	delete menumgr_;
}