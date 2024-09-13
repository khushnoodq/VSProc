#pragma once
/*+
________________________________________________________________________

	Author: Khushnood Qadir
________________________________________________________________________

-*/

#include "uibasemod.h"

#include "Basic/commondefs.h"
#include <QMainWindow>


mExpClass(uiBase) uiMainWin : public QMainWindow
{
public:
					uiMainWin(QWidget* parent=nullptr);
					~uiMainWin();
protected:
};
