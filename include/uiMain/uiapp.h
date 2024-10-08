#pragma once
/*+
________________________________________________________________________

	Author: Khushnood Qadir
________________________________________________________________________

-*/

#include "uimainmod.h"
#include "Basic/commondefs.h"

#include <QMainWindow>

class uiMenuMgr;
class uiApplMgr;

mExpClass(uiMain) uiMainApp : public QMainWindow
{
	Q_OBJECT;

public:
							m_DisableCopy(uiMainApp)
							uiMainApp();
							~uiMainApp();

	uiMenuMgr&				menuMgr()			{ return *menumgr_; }
	uiApplMgr&				applMgr()			{ return *applmgr_; }

signals:
	void					finalized();

protected:

	uiMenuMgr*				menumgr_;
	uiApplMgr*				applmgr_;
};

mGlobal(uiMain) uiMainApp& AppMainWin();