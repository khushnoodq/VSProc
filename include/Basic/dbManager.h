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
    static std::shared_ptr<dbManager>	getDBManagerInstance();
    bool				isOK() const;
    bool				isOpen() const;
    bool				createDB(const std::string&);
private:
					m_DisableCopy(dbManager)
					dbManager();
					~dbManager();

    static std::shared_ptr<dbManager>	dbmanager_;
    static std::mutex			mutex_;

    QSqlDatabase			db_;
};