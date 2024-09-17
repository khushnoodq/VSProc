#pragma once
/*+
________________________________________________________________________

	Author: Khushnood Qadir
________________________________________________________________________

-*/

#include "uicompsmod.h"
#include "Basic/commondefs.h"

#include <QDialog>

mExpClass(uiComps) uiCreateProjDlg : public QDialog
{
	Q_OBJECT;
public:
						uiCreateProjDlg(QWidget*,const char*);
						~uiCreateProjDlg();
protected:
};