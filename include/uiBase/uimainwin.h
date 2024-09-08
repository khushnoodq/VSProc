#pragma once
/*+
________________________________________________________________________

	Author: Khushnood Qadir
________________________________________________________________________

-*/

#include <QMainWindow>

class uiMainWin : public QMainWindow
{
public:
	uiMainWin(QWidget* parent=nullptr);
	~uiMainWin();
protected:
	void	setupUi();
};
