#pragma once
/*+
________________________________________________________________________

	Author: Prajjaval Singh
________________________________________________________________________

-*/

#include "dbManager.h"

mExpClass(Basic) WellDBManager : public dbManager
{
public:
				    WellDBManager();
				    ~WellDBManager();
    static std::string		    typeName();
    std::string			    getType() const override;
    
    mRegisterDBMan(WellDBManager);
protected:
				
				

    static std::shared_ptr<dbManager>	    getInstance();
};
