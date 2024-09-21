/*+
________________________________________________________________________

	Author: Khushnood Qadir
________________________________________________________________________

-*/

#include "uiMain/uiappmgr.h"

uiApplMgr::uiApplMgr( uiMainApp* appl )
	: QObject()
	, appl_( *appl )
{}


uiApplMgr::~uiApplMgr()
{}


void uiApplMgr::newProjClicked()
{}


void uiApplMgr::openProjClicked()
{
	if ( !uiopenprojdlg_ )
		uiopenprojdlg_ = new uiOpenProjDlg( &appl_ );

	uiopenprojdlg_->show();
}