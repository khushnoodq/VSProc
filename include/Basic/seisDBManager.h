#pragma once
/*+
________________________________________________________________________

	Author: Prajjaval Singh
________________________________________________________________________

-*/

#include "dbManager.h"


mExpClass(Basic) SeisDBManager : public dbManager
{
public:
				    SeisDBManager();
				    ~SeisDBManager();
    static std::string		    typeName();
    std::string			    getType() const override;

    mRegisterDBMan(SeisDBManager);
protected:
					    
					   

    static std::shared_ptr<dbManager>	    getInstance();
};
