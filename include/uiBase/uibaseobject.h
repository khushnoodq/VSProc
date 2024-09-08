#pragma once
/*+
________________________________________________________________________

	Author: Khushnood Qadir
________________________________________________________________________

-*/
/*
#include "Basic/namedobj.h"

class uiBody;
mFDQtclass(QWidget);

class uiBaseObject : public NamedCallBacker
{
public:
    virtual                     ~uiBaseObject();
                                mOD_DisableCopy(uiBaseObject)

                                    // implementation: uiobj.cc
        void                        finalize();
        bool                        finalized() const;
        void                        clear();

        virtual void                translateText() {}
        /*!<Triggers translation of object and all
            members to current language. 

inline const uiBody* body() const { return body_; }
inline uiBody* body() { return body_; }*/