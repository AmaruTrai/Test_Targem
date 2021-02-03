#include "Compare.h"


// Operator () overloading
bool Ñompare::operator()(const DString & lhs,const DString & rhs)
{
	size_t size_ = 0;
	lhs.Size() > rhs.Size() ? size_ = lhs.Size() : size_ = rhs.Size();
	for (size_t i = 0; i < size_; ++i)
	{
		char lSym = lhs.At(i);
		char rSym = rhs.At(i);
		if (('z' >= lSym) && (lSym >= 'a'))
		{
			lSym -= 32;
		}
		if (('z' >= rSym) && (rSym >= 'a'))
		{
			rSym -= 32;
		}
		if (lSym > rSym)
		{
			return  true;
		}
		if (lSym < rSym)
		{
			return  false;
		}
	}
	return  false;
}