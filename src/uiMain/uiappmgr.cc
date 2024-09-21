/*+
________________________________________________________________________

	Author: Khushnood Qadir
________________________________________________________________________

-*/

#include "uiMain/uiappmgr.h"

#include <iostream>

uiApplMgr::uiApplMgr( uiMainApp* appl )
	: QObject()
	, appl_( *appl )
{}


uiApplMgr::~uiApplMgr()
{}


void uiApplMgr::newProjClicked()
{
	uiNewProjDlg dlg( &appl_ );
	if ( !dlg.exec() )
		return;
}


void uiApplMgr::openProjClicked()
{
	uiOpenProjDlg dlg( &appl_ );
	if ( !dlg.exec() )
		return;
}


void uiApplMgr::openRecentProj()
{}