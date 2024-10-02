/*+
________________________________________________________________________

	Author: Prajjaval Singh
________________________________________________________________________

-*/

#include "Basic/seisDBManager.h"

using namespace std;


shared_ptr<dbManager> SeisDBManager::getInstance()
{
    static shared_ptr<SeisDBManager> dbmanager = make_shared<SeisDBManager>();
    return dbmanager;
}


SeisDBManager::SeisDBManager()
    :dbManager()
{
    db_ = QSqlDatabase::addDatabase("QPSQL");
    db_.setHostName("VSProcSeis");
    db_.setDatabaseName("SeisDB");
    const auto creds = getCredentials();
    if (creds.has_value())
    {
	const auto cred = creds.value();
	db_.setUserName(QString::fromStdString(cred.username));
	db_.setPassword(QString::fromStdString(cred.password));
    }

}


SeisDBManager::~SeisDBManager()
{
}


std::string SeisDBManager::typeName()
{
    return "SEISDB";
}


std::string SeisDBManager::getType() const
{
    return typeName();
}