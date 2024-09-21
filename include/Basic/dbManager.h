#pragma once
/*+
________________________________________________________________________

	Author: Prajjaval Singh
________________________________________________________________________

-*/


#include "basicmod.h"
#include "commondefs.h"

#include <mutex>

#include <QSqlDatabase>

mExpClass(Basic) dbManager : QSqlDatabase
{
public:
    virtual std::shared_ptr<dbManager>	getInstance() = 0;
    virtual bool			isOK() const;
    virtual bool			isOpen() const;

protected:
					m_DisableCopy(dbManager)
					dbManager();
					~dbManager();

    std::shared_ptr<dbManager>		dbmanager_;
    std::mutex				mutex_;

    struct Credentials
    {
	std::string username;
	std::string password;
    };

    Credentials				getCredentials() const;

    QSqlDatabase			db_;

private:
    Credentials readCredentialsFromBinaryFile(const std::string&) const;
};
