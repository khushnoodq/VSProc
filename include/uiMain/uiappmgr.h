#pragma once
/*+
________________________________________________________________________

	Author: Khushnood Qadir
________________________________________________________________________

-*/

#include "uimainmod.h"
#include "Basic/commondefs.h"

#include "uiComps/uiselprojdlg.h"

#include "uiapp.h"

class uiSelectProjDlg;

mExpClass(uiMain) uiApplMgr : public QObject
{
	Q_OBJECT;

public:
							uiApplMgr(uiMainApp*);
							~uiApplMgr();
						
public slots:
	void					selProjClickedCB();

protected:

	uiMainApp&				appl_;

	uiSelectProjDlg*		uiselprojdlg_					= nullptr;
};