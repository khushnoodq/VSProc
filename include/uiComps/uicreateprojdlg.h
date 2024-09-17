#pragma once
/*+
________________________________________________________________________

	Author: Khushnood Qadir
________________________________________________________________________

-*/

#include "Basic/commondefs.h"

#include <QDialog>

mExpClass(uiComps) uiCreateProjDlg : public QDialog
{
	Q_OBJECT;
public:
						uiCreateProjDlg(QParent*,const char*);
						~uiCreateProjDlg();
protected:
};