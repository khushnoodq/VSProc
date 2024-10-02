/*+
________________________________________________________________________

	Author: Prajjaval Singh
________________________________________________________________________

-*/

#include "Basic/dbManager.h"

#include <iostream>
#include <fstream>
#include <string>

#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QString>

using namespace std;
static unordered_map<std::string, std::function<std::shared_ptr<dbManager>()>> registry;

void dbManager::registerClass(const std::string& type, std::function<std::shared_ptr<dbManager>()> creator)
{
    registry[type] = creator;
}


shared_ptr<dbManager> dbManager::createInstance(const std::string& type)
{
    auto it = registry.find(type);
    if (it != registry.end())
    {
        it->second();
    }

    return nullptr;
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


optional<dbManager::Credentials> dbManager::readCredentialsFromBinaryFile(const std::string& filename) const
{
    ifstream file(filename, std::ios::binary | std::ios::in);
    if (!file)
    {
        cerr << "Error: Could not open file!" << endl;
        return nullopt;
    }

    dbManager::Credentials creds;

    size_t usernameLength, passwordLength;
    file.read(reinterpret_cast<char*>(&usernameLength), sizeof(usernameLength));
    file.read(reinterpret_cast<char*>(&passwordLength), sizeof(passwordLength));

    // Resizing the strings
    creds.username.resize(usernameLength);
    creds.password.resize(passwordLength);

    // Read the username and password
    file.read(&creds.username[0], usernameLength);
    file.read(&creds.password[0], passwordLength);

    file.close();

    return creds;
}

optional<dbManager::Credentials> dbManager::getCredentials() const
{
    QString appPath = QCoreApplication::applicationDirPath();
    QFileInfo appInfo(appPath);
    //Need to go to data/credential.bin location
    return readCredentialsFromBinaryFile(appInfo.dir().absolutePath().toStdString());
}
