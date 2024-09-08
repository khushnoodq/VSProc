#pragma once
/*+
________________________________________________________________________

	Author: Khushnood Qadir
________________________________________________________________________

-*/

#include <string>

class NamedObject
{
public:
						NamedObject( const char* nm = nullptr )
							: name_(nm)			{}
						NamedObject( const NamedObject& oth )
							: name_(oth.name()) {}
	virtual				~NamedObject()		{}

	virtual std::string	name() const		{ return name_; }
	virtual void		setName( const char* nm ) { name_ = nm; }
protected:

	std::string			name_;
};
