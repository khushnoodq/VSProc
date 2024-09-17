/*+
________________________________________________________________________

	Author: Khushnood Qadir
________________________________________________________________________

-*/

#include "uiComps/uiopenprojdlg.h"

#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

uiOpenProjDlg::uiOpenProjDlg( QWidget* p )
	: QDialog( p )
{
	setWindowTitle( QString("Select Project") );
	setModal( false );

	auto* lblbl = new QLabel( "Recent locations ...", this );
	recentlb_ = new QListWidget( this );
	auto* pathfldlbl = new QLabel( "Folder: ", this );
	pathfld_ = new QLineEdit( this );
	browsepb_ = new QPushButton( "Browse .. ", this );

	QVBoxLayout* mainlayout = new QVBoxLayout;
	mainlayout->addWidget( lblbl );
	mainlayout->addWidget( recentlb_ );

	QHBoxLayout* horlayout = new QHBoxLayout();
	horlayout->addWidget( pathfldlbl );
	horlayout->addWidget( pathfld_ );
	horlayout->addWidget( browsepb_ );

	mainlayout->addLayout( horlayout );
	setLayout( mainlayout );
}


uiOpenProjDlg::~uiOpenProjDlg()
{}