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


mExpClass(uiComps) uiNewProjDlg : public QFileDialog
{
	Q_OBJECT;
public:
							uiNewProjDlg( QWidget* parent=nullptr );
							~uiNewProjDlg();

	const std::filesystem::path&	getSelDir() const	{ return seldir_; }

private slots:

	void					done(int r) override;

private:

	std::filesystem::path	seldir_;

};


// To-do: A QDialog class for fetching new Project Information from user.


mExpClass(uiComps) uiOpenProjDlg : public QFileDialog
{
	Q_OBJECT;
public:
							uiOpenProjDlg( QWidget* parent=nullptr );
							~uiOpenProjDlg();

	const std::filesystem::path&	getSelDir() const	{ return seldir_; }

private slots:

	void					done(int r) override;

private:

	std::filesystem::path	seldir_;
};