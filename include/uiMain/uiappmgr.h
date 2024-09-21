#pragma once
/*+
________________________________________________________________________

	Author: Khushnood Qadir
________________________________________________________________________

-*/

#include "uimainmod.h"
#include "Basic/commondefs.h"

#include "uiComps/uiprojectdlgs.h"

#include "uiapp.h"

class uiOpenProjDlg;

mExpClass(uiMain) uiApplMgr : public QObject
{
	Q_OBJECT;

public:
							uiApplMgr(uiMainApp*);
							~uiApplMgr();
						
public slots:

	void					newProjClicked();
	void					openProjClicked();

protected:

	uiMainApp&				appl_;

	uiOpenProjDlg*			uiopenprojdlg_					= nullptr;
};