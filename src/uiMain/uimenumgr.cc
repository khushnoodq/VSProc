/*+
________________________________________________________________________

	Author: Khushnood Qadir
________________________________________________________________________

-*/

#include "uiMain/uimenumgr.h"
#include "uiMain/menuids.h"

#include "Basic/commonstrs.h"

#include <QMenuBar>

uiMenuMgr::uiMenuMgr( uiMainApp* app )
	: appl_( *app )
{
	auto* mb = appl_.menuBar();
	filemenu_ = mb->addMenu( QString::fromStdString(sKeyUi::sFile()) );
	fillFileMenu();
	procmenu_ = mb->addMenu( QString::fromStdString(sKeyUi::sProcessing()) );
	utilsmenu_ = mb->addMenu( QString::fromStdString(sKeyUi::sUtilities()) );
	helpmenu_ = mb->addMenu( QString::fromStdString(sKeyUi::sHelp()) );
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
	auto* menunm = new QMenu( QString::fromStdString(stdstr), parent ); 


void uiMenuMgr::fillFileMenu()
{
	mAddSubMenu( projmenu, sKeyUi::sProject(), filemenu_)
	mAddSubMenu( openmenu, sKeyUi::sOpen(), filemenu_ )
	mAddSubMenu( savemenu, sKeyUi::sSave(), filemenu_ )
	mAddSubMenu( vspmenu, sKeyUi::sVSP(), filemenu_ )
}


void uiMenuMgr::fillProcMenu()
{}


void uiMenuMgr::fillUtilsMenu()
{}


void uiMenuMgr::fillHelpMenu()
{}