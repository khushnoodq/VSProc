/*+
________________________________________________________________________

	Author: Prajjaval Singh
________________________________________________________________________

-*/

#include "Basic/wellDBManager.h"

using namespace std;

shared_ptr<dbManager> WellDBManager::getInstance()
{
    if (!dbmanager_)
    {
	lock_guard<mutex> lock(mutex_);
	if (!dbmanager_)
	{
	    dbmanager_ = make_shared<dbManager>(new WellDBManager());
	}
    }

    return dbmanager_;
}


WellDBManager::WellDBManager()
    : dbManager()
{
    db_ = QSqlDatabase::addDatabase("QPSQL");
    db_.setHostName("VSProcWell");
    db_.setDatabaseName("WellDB");
    const auto creds = getCredentials();
    db_.setUserName(QString::fromStdString(creds.username));
    db_.setPassword(QString::fromStdString(creds.password));
}


WellDBManager::~WellDBManager()
{
}