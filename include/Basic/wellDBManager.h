#pragma once
/*+
________________________________________________________________________

	Author: Prajjaval Singh
________________________________________________________________________

-*/

#include "dbManager.h"

mExpClass(Basic) WellDBManager : dbManager
{
public:
    std::shared_ptr<dbManager>	getInstance() override;
    bool			isOK() const override;
    bool			isOpen() const override;
protected:
				WellDBManager();
				~WellDBManager();
};