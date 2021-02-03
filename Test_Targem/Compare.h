#pragma once
#include "DString.h"


// Functor for DString comparison (returns true if lhs is more rhs reicht in lexicographic order context)
class Ñompare
{
public:
	// Operator () overloading
	bool operator()(const DString& lhs,const DString& rhs);
};