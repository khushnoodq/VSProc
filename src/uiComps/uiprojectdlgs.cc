/*+
________________________________________________________________________

	Author: Khushnood Qadir
________________________________________________________________________

-*/

#include "uiComps/uiprojectdlgs.h"

#include <QErrorMessage>

uiNewProjDlg::uiNewProjDlg( QWidget* p )
	: QFileDialog( p )
{
	setWindowTitle( QString("Create Project") );
	setLabelText( QFileDialog::Accept, "Create" );
	setFileMode( QFileDialog::Directory );
	setViewMode( QFileDialog::Detail );
	setOption( QFileDialog::ShowDirsOnly );
	setAcceptMode( QFileDialog::AcceptSave );
}


uiNewProjDlg::~uiNewProjDlg()
{}


void uiNewProjDlg::done( int result )
{
	if ( result != QFileDialog::Accepted )
	{
		QFileDialog::done( result );
		return;
	}

	seldir_ = selectedFiles().first().toStdString();
	QString errmsg;
	if ( std::filesystem::exists(seldir_) )
	{
		errmsg = "Project already exists, please use \"Open\" menu";
		errmsg += "to access it.";
		QErrorMessage uimsg( this );
		uimsg.showMessage( errmsg );
		return;
	}

	if ( !std::filesystem::create_directories(seldir_) )
	{
		errmsg = "Failed to create new Project";
		QErrorMessage uimsg( this );
		uimsg.showMessage( errmsg );
		return;
	};

	QFileDialog::done( result );
}


// --> uiOpenProjDlg
uiOpenProjDlg::uiOpenProjDlg( QWidget* p )
	: QFileDialog( p )
{
	setWindowTitle( QString("Open Project") );
	setLabelText( QFileDialog::Accept, "Open" );
	setFileMode( QFileDialog::Directory );
	setViewMode( QFileDialog::Detail );
	setOption( QFileDialog::ShowDirsOnly );
}


uiOpenProjDlg::~uiOpenProjDlg()
{}


void uiOpenProjDlg::done( int result )
{
	if ( result != QFileDialog::Accepted )
	{
		QFileDialog::done( result );
		return;
	}

	seldir_ = selectedFiles().first().toStdString();
	// -- to-do ---
	// Some checks.. Might add a list here first.
	QFileDialog::done( result );
}