/*+
________________________________________________________________________

	Author: Prajjaval Singh
________________________________________________________________________

-*/

#include "Basic/wellDBManager.h"

using namespace std;

shared_ptr<dbManager> WellDBManager::getInstance()
{
    static shared_ptr<WellDBManager> dbmanager = make_shared<WellDBManager>();
    return dbmanager;
}



WellDBManager::WellDBManager()
    : dbManager()
{
    db_ = QSqlDatabase::addDatabase("QPSQL");
    db_.setHostName("VSProcWell");
    db_.setDatabaseName("WellDB");
    const auto creds = getCredentials();
    if (creds.has_value())
    {
	const auto cred = creds.value();
	db_.setUserName(QString::fromStdString(cred.username));
	db_.setPassword(QString::fromStdString(cred.password));
    }
}


WellDBManager::~WellDBManager()
{
}


std::string WellDBManager::typeName()
{
    return "WELLDB";
}


std::string WellDBManager::getType() const
{
    return typeName();
}