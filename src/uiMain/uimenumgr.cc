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
#include <QWidgetAction>

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
	menunm = new QMenu( QString::fromStdString(stdstr), parent ); \
	parent->addMenu( menunm );

#define mAddAction( nm, stdstr, parent ) \
	auto* nm = new QAction( QString::fromStdString(stdstr), parent ); \
	parent->addAction( nm );


void uiMenuMgr::fillFileMenu()
{
	mAddAction( newmenu, sKeyUi::sNew(), filemenu_ )
	mAddSubMenu( openmenu_, sKeyUi::sOpen(), filemenu_ )
	fillOpenMenu();
	mAddAction( savemenu, sKeyUi::sSave(), filemenu_ )
	mAddAction( vspmenu, sKeyUi::sVSP(), filemenu_ )

	mConnectMenuWithAppMgr( newmenu, newProjClicked )
}


void uiMenuMgr::fillOpenMenu()
{
	mAddAction( openlocalmenu, "location", openmenu_ )

	//-> get from API to access recent paths. Current impl is for test.
	const std::vector<std::filesystem::path> paths;
	if ( !paths.empty() )
	{
		openmenu_->addSeparator();
		auto* recenttxt = new QLabel( "Recent projects ...", &appl_ );
		auto* recenttxtaction = new QWidgetAction( &appl_ );
		recenttxtaction->setDefaultWidget( recenttxt );
		openmenu_->addAction( recenttxtaction );
		openmenu_->addSeparator();

		for ( const auto& path : paths )
		{
			mAddAction( action, path.u8string(), openmenu_ )
			mConnectMenuWithAppMgr( action, openRecentProj )
		}
	}

	mConnectMenuWithAppMgr( openlocalmenu, openProjClicked )
}


void uiMenuMgr::fillProcMenu()
{}


void uiMenuMgr::fillUtilsMenu()
{}


void uiMenuMgr::fillHelpMenu()
{}