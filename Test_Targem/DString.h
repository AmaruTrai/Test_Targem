#pragma once

#include <string>

struct DChar
{
	char	sym				= 0;
	DChar*	nextSym			= nullptr;
	DChar*  previousSym		= nullptr;
};

class DString
{

	friend	DString& operator+= (DString& left, const DString& right);

public:
	// Constructor/Destructor
				DString();
				~DString();

	// Constructor accepting a pointer to an array of symbols and the length of the array
				DString(const char* str, size_t strSize);

	// Constructor accepting a pointer to C-style string
				DString(const char* str);

	// Constructor accepting a pointer to string
				DString(const std::string* str);

	// Copy constructor
				DString(const DString& dstring);

	// Move constructor
				DString(DString&& dstring) noexcept;

	// Assignment operator
	DString&	operator=(const DString & right);

	// Move assignment operator
	DString&	operator=(DString&& right) noexcept;

	// Method returning DString size
	size_t		Size() const;

	// Method that adds a sym to the end of a DString
	void		Insert(const char& sym);

	// Method returning element by index i
	char		At(size_t i) const;

	// Method to remove the last element
	bool		Remove();

private:
	
	DChar*	startSym_	=	nullptr;
	DChar*	endSym_		=	nullptr;
	size_t	size_		=	0;

};

// Operator += overloading
DString& operator+= (DString& left, const DString& right);

// Operator + overloading
DString operator+ (const DString& left, const DString& right);

