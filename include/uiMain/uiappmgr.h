#pragma once
/*+
________________________________________________________________________

	Author: Khushnood Qadir
________________________________________________________________________

-*/

#include "uimainmod.h"
#include "Basic/commondefs.h"

#include "uiapp.h"

mExpClass(uiMain) uiApplMgr
{
public:
						uiApplMgr(uiMainApp&);
						~uiApplMgr();
protected:

	uiMainApp&			appl_;
};