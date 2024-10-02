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

mExpClass(Basic) dbManager : public QSqlDatabase
{
public:
    virtual std::string			getType() const = 0;
    static std::shared_ptr<dbManager>	createInstance(const std::string&);
    static void				registerClass(const std::string& type,
					std::function<std::shared_ptr<dbManager>()> creator);
    virtual bool			isOK() const;
    virtual bool			isOpen() const;
#define mRegisterDBMan(DBManName) \
    struct Register##DBManName \
    { \
	Register##DBManName() \
	{ \
	    dbManager::registerClass(DBManName::typeName(), &DBManName::getInstance); \
	} \
    } \
    Register##DBManName; \
protected:
					m_DisableCopy(dbManager)
					dbManager();
					~dbManager();

    struct Credentials
    {
	std::string username;
	std::string password;
    };

    std::optional<Credentials>		getCredentials() const;

    QSqlDatabase			db_;

private:
    std::optional<Credentials> readCredentialsFromBinaryFile(const std::string&) const;
};
