/*+
________________________________________________________________________

	Author: Khushnood Qadir
________________________________________________________________________

-*/

#include "uiMain/uiapp.h"
#include "uiMain/uimenumgr.h"
#include "uiMain/uiappmgr.h"

uiMainApp& AppMainWin()
{
    mDefineStaticLocalObject( uiMainApp, instance, )
    return instance;
}


uiMainApp::uiMainApp()
	: QMainWindow( nullptr )
{
	setWindowTitle( "VSProc" );
	menumgr_ = new uiMenuMgr( this );
	applmgr_ = new uiApplMgr( *this );
}


uiMainApp::~uiMainApp()
{
	delete menumgr_;
	delete applmgr_;
}