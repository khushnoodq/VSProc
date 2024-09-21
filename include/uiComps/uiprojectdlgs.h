#pragma once
/*+
________________________________________________________________________

	Author: Khushnood Qadir
________________________________________________________________________

-*/

#include "uicompsmod.h"
#include "Basic/commondefs.h"

#include <QFileDialog>
#include <QLabel>
#include <QListWidget>

mExpClass(uiComps) uiOpenProjDlg : public QFileDialog
{
	Q_OBJECT;
public:
						uiOpenProjDlg(QWidget* parent=nullptr);
						~uiOpenProjDlg();
protected:

	void				accept() override;
};