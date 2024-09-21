#pragma once
/*+
________________________________________________________________________

	Author: Khushnood Qadir
________________________________________________________________________

-*/

#include "uimainmod.h"
#include "uiapp.h"

#include <QObject>
#include <QMenu>
#include <QToolBar>

mExpClass(uiMain) uiMenuMgr : public QObject
{
	Q_OBJECT;
	friend class	uiMainApp;

public:
					
	QMenu*			fileMenu() const		{ return filemenu_; }
	QMenu*			procMenu() const		{ return procmenu_; }
	QMenu*			utilsMenu() const		{ return utilsmenu_; }
	QMenu*			helpMenu() const		{ return helpmenu_; }

protected:
					uiMenuMgr(uiMainApp*);
					~uiMenuMgr();

	void			initMenuItems();
	void			fillFileMenu();
	void			fillOpenMenu();
	void			fillProcMenu();
	void			fillUtilsMenu();
	void			fillHelpMenu();

	uiMainApp&		appl_;

	QMenu*			filemenu_								= nullptr;
	QMenu*			openmenu_								= nullptr;
	QMenu*			procmenu_								= nullptr;
	QMenu*			utilsmenu_								= nullptr;
	QMenu*			helpmenu_								= nullptr;
};