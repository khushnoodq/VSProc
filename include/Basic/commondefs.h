#pragma once
/*+
________________________________________________________________________

	Author: Khushnood Qadir
________________________________________________________________________

-*/


#define mExp( module )                  Export_##module
#define mExpClass( module )             class mExp( module )
#define mExpStruct( module )            struct mExp( module )

#define m_DisableCopy(clss) \
    clss( const clss& ) = delete; \
    clss& operator=( const clss& ) = delete;

//--- Qt class and namespace handling

#ifndef QT_NAMESPACE
# define mFDQtclass(cls) class cls;
# define mQtclass(cls) ::cls
# define mUseQtnamespace
#else
# define mFDQtclass(cls) namespace QT_NAMESPACE { class cls; }
# define mQtclass(cls) ::QT_NAMESPACE::cls
# define mUseQtnamespace using namespace ::QT_NAMESPACE;
#endif
