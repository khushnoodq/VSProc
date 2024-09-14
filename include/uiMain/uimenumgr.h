#pragma once
/*+
________________________________________________________________________

	Author: Khushnood Qadir
________________________________________________________________________

-*/

#include "uimainmod.h"
#include "uiapp.h"

#include <QMenu>
#include <QToolBar>

mExpClass(uiMain) uiMenuMgr
{

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
	void			fillProcMenu();
	void			fillUtilsMenu();
	void			fillHelpMenu();

	uiMainApp&		appl_;

	QMenu*			filemenu_;
	QMenu*			procmenu_;
	QMenu*			utilsmenu_;
	QMenu*			helpmenu_;
};