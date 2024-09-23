/*+
________________________________________________________________________

	Author: Prajjaval Singh
________________________________________________________________________

-*/

#include "Basic/seisDBManager.h"

using namespace std;

shared_ptr<dbManager> SeisDBManager::getInstance()
{
    if (!dbmanager_)
    {
	lock_guard<mutex> lock(mutex_);
	if (!dbmanager_)
	{
	    dbmanager_ = make_shared<dbManager>(new SeisDBManager());
	}
    }

    return dbmanager_;
}


SeisDBManager::SeisDBManager()
    :dbManager()
{
    db_ = QSqlDatabase::addDatabase("QPSQL");
    db_.setHostName("VSProcSeis");
    db_.setDatabaseName("SeisDB");
    const auto creds = getCredentials();
    db_.setUserName(QString::fromStdString(creds.username));
    db_.setPassword(QString::fromStdString(creds.password));

}


SeisDBManager::~SeisDBManager()
{
}