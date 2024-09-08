#pragma once
/*+
________________________________________________________________________

	Author: Khushnood Qadir
________________________________________________________________________

-*/

#include "Basic/commondefs.h"

mFDQtclass(QWidget);

class uiBody
{
public:
    virtual                     ~uiBody();
                                mOD_DisableCopy(uiBody)

    virtual void                finalize() {}
    virtual bool                finalized() const { return false; }
    virtual void                clear() {}
    virtual void                fontchanged() {}


    //! can return nullptr
    inline const mQtclass(QWidget*)     qwidget() const
                                        { return qwidget_(); }
    //! can return nullptr
    inline mQtclass(QWidget*)           qwidget()
        { return const_cast<mQtclass(QWidget*)>(qwidget_()); }

protected:
                                uiBody();

    virtual const mQtclass(QWidget*)    qwidget_() const = 0;

};