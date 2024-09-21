#pragma once
/*+
________________________________________________________________________

	Author: Prajjaval Singh
________________________________________________________________________

-*/

#include "dbManager.h"

mExpClass(Basic) SeisDBManager : dbManager
{
public:
    std::shared_ptr<dbManager>	getInstance() override;
    bool			isOK() const override;
    bool			isOpen() const override;
protected:
				SeisDBManager();
				~SeisDBManager();
};