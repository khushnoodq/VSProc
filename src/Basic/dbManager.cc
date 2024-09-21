/*+
________________________________________________________________________

	Author: Prajjaval Singh
________________________________________________________________________

-*/

#include "Basic/dbManager.h"

using namespace std;

shared_ptr<dbManager> dbManager::getDBManagerInstance()
{
    if (!dbmanager_)
    {
	lock_guard<mutex> lock(mutex_);
	if (!dbmanager_)
	{
	    dbmanager_ = make_shared<dbManager>(new dbManager());
	}
    }

    return dbmanager_;
}


dbManager::dbManager()
    : QSqlDatabase()
{
}

dbManager::~dbManager()
{
}


bool dbManager::isOK() const
{
    return db_.isValid();
}


bool dbManager::isOpen() const
{
    return db_.isOpen();
}



