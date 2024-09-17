/*+
________________________________________________________________________

	Author: Khushnood Qadir
________________________________________________________________________

-*/

#include "uiMain/uiappmgr.h"

#include "uiComps/uiopenprojdlg.h"

uiApplMgr::uiApplMgr( uiMainApp* appl )
	: QObject()
	, appl_( *appl )
{}


uiApplMgr::~uiApplMgr()
{}


void uiApplMgr::selProjClickedCB()
{
	if ( !uiopenprojdlg_ )
		uiopenprojdlg_ = new uiOpenProjDlg( &appl_ );

	uiopenprojdlg_->show();
}