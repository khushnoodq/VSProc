/*+
________________________________________________________________________

	Author: Khushnood Qadir
________________________________________________________________________

-*/

#include "uiComps/uiprojectdlgs.h"

#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

uiOpenProjDlg::uiOpenProjDlg( QWidget* p )
	: QFileDialog( p )
{
	setWindowTitle( QString("Select Project") );
	setModal( false );
	setFileMode( QFileDialog::Directory );
}


uiOpenProjDlg::~uiOpenProjDlg()
{}


void uiOpenProjDlg::accept()
{}