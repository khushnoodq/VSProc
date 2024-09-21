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
#include <QFileInfo>
#include <QString>

using namespace std;

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


dbManager::Credentials dbManager::readCredentialsFromBinaryFile(const std::string& filename) const
{
    ifstream file(filename, std::ios::binary | std::ios::in);
    if (!file)
    {
        cerr << "Error: Could not open file!" << endl;
        return;
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

dbManager::Credentials dbManager::getCredentials() const
{
    QString appPath = QCoreApplication::applicationDirPath();
    QFileInfo appInfo(appPath);
    //Need to go to data/credential.bin location
    return readCredentialsFromBinaryFile(appInfo.dir().absolutePath().toStdString());
}
