/*+
________________________________________________________________________

	Author: Khushnood Qadir
________________________________________________________________________

-*/

#include "uiMain/uiappmgr.h"

#include "uiComps/uiselprojdlg.h"

uiApplMgr::uiApplMgr( uiMainApp* appl )
	: QObject()
	, appl_( *appl )
{}


uiApplMgr::~uiApplMgr()
{}


void uiApplMgr::selProjClickedCB()
{
	if ( !uiselprojdlg_ )
		uiselprojdlg_ = new uiSelectProjDlg( &appl_ );

	uiselprojdlg_->show();
}