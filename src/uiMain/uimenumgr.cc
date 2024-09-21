/*+
________________________________________________________________________

	Author: Khushnood Qadir
________________________________________________________________________

-*/

#include "uiMain/uimenumgr.h"

#include "uiMain/uiappmgr.h"
#include "uiMain/uimenuids.h"


#include "Basic/commonstrs.h"

#include <QMenuBar>

#define mConnectMenuWithAppMgr( menu, func ) \
{ \
	connect( menu, &QAction::triggered, \
			 &appl_.applMgr(), &uiApplMgr::func ); \
}


uiMenuMgr::uiMenuMgr( uiMainApp* app )
	: QObject()
	, appl_( *app )
{
	auto* mb = appl_.menuBar();
	filemenu_ = mb->addMenu( QString::fromStdString(sKeyUi::sFile()) );
	procmenu_ = mb->addMenu( QString::fromStdString(sKeyUi::sProcessing()) );
	utilsmenu_ = mb->addMenu( QString::fromStdString(sKeyUi::sUtilities()) );
	helpmenu_ = mb->addMenu( QString::fromStdString(sKeyUi::sHelp()) );
	connect( &appl_, &uiMainApp::finalized, this, &uiMenuMgr::initMenuItems );
}


uiMenuMgr::~uiMenuMgr()
{}


void uiMenuMgr::initMenuItems()
{
	fillFileMenu();
	fillProcMenu();
	fillUtilsMenu();
	fillHelpMenu();
}


#define mAddSubMenu( menunm, stdstr, parent ) \
	auto* menunm = new QMenu( QString::fromStdString(stdstr), parent ); \
	parent->addMenu( menunm );

#define mAddAction( nm, stdstr, parent ) \
	auto* nm = new QAction( QString::fromStdString(stdstr), parent ); \
	parent->addAction( nm );


void uiMenuMgr::fillFileMenu()
{
	mAddAction(newmenu, sKeyUi::sNew(), filemenu_)
	mAddAction(openmenu, sKeyUi::sOpen(), filemenu_)
	mAddSubMenu(savemenu, sKeyUi::sSave(), filemenu_)
	mAddSubMenu(vspmenu, sKeyUi::sVSP(), filemenu_)

	mConnectMenuWithAppMgr( newmenu, newProjClicked )
	mConnectMenuWithAppMgr( openmenu, openProjClicked )
}


void uiMenuMgr::fillProcMenu()
{}


void uiMenuMgr::fillUtilsMenu()
{}


void uiMenuMgr::fillHelpMenu()
{}