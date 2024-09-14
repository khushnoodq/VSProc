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

mExpClass(uiMain) uiMainApp : public QMainWindow
{
public:
					m_DisableCopy(uiMainApp)
					uiMainApp();
					~uiMainApp();
protected:

	uiMenuMgr*		menumgr_;
};

mGlobal(uiMain) uiMainApp& AppMainWin();