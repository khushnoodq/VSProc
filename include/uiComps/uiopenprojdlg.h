#pragma once
/*+
________________________________________________________________________

	Author: Khushnood Qadir
________________________________________________________________________

-*/

#include "uicompsmod.h"
#include "Basic/commondefs.h"

#include <QDialog>
#include <QLabel>
#include <QListWidget>

mExpClass(uiComps) uiOpenProjDlg : public QDialog
{
	Q_OBJECT;
public:
						uiOpenProjDlg(QWidget* parent=nullptr);
						~uiOpenProjDlg();
protected:

	QListWidget*		recentlb_					= nullptr;
	QPushButton*		browsepb_						= nullptr;
	QLineEdit*			pathfld_					= nullptr;
};