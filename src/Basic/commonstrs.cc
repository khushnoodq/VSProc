/*+
________________________________________________________________________

	Author: Khushnood Qadir
________________________________________________________________________

-*/

#include "Basic/commonstrs.h"

#define mCreateAndRet(fnm, ret) \
	const std::string& fnm() \
	{ \
		static std::string retstr = ret; \
		return retstr; \
	}

namespace sKeyUi
{
mCreateAndRet( sCreate, "Create" )
mCreateAndRet( sExport, "Export" )
mCreateAndRet( sImport, "Import" )
mCreateAndRet( sFile, "File" )
mCreateAndRet( sHelp, "Help" )
mCreateAndRet( sNew, "New" )
mCreateAndRet( sManage, "Manage" )
mCreateAndRet( sOpen, "Open" )
mCreateAndRet( sProcessing, "Processing" )
mCreateAndRet( sProject, "Project" )
mCreateAndRet( sRecent, "Recent" )
mCreateAndRet( sSave, "Save" )
mCreateAndRet( sUtilities, "Utilities" )
mCreateAndRet( sVSP, "VSP" )
} //->namespace sKeyUi