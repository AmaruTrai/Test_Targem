#include "DString.h"
#include <iostream>

// Constructor
DString::DString() 
{
	startSym_	= new DChar;
	endSym_		= startSym_;
}

// Destructor
DString::~DString()
{
	if (startSym_ != nullptr)
	{
		while(size_)
		{
			Remove();
		}
	}
}

// Constructor accepting a pointer to an array of symbols and the length of the array
DString::DString(const char* str, size_t strSize)
{
	startSym_ = new DChar;
	endSym_ = startSym_;
	if (str != nullptr && strSize)
	{
		for(size_t i = 0; i < strSize; ++i)
		{
			Insert(str[i]);
		}
	}
}

// Constructor accepting a pointer to C-style string
DString:: DString(const char* str)
{
	startSym_ = new DChar;
	endSym_ = startSym_;
	if (str != nullptr)
	{
		size_t i = 0;
		while (str[i])
		{
			Insert(str[i]);
			++i;
		}
	}
}

// Constructor accepting a pointer to string
DString::DString(const std::string* str)
{
	startSym_ = new DChar;
	endSym_ = startSym_;
	if (str != nullptr)
	{
		size_t strSize = str->size();
		for (size_t i = 0; i < strSize; ++i)
		{
			Insert(str->at(i));
		}
	}
}

// Copy constructor
DString::DString(const DString& dstr)
{
	startSym_ = new DChar;
	endSym_ = startSym_;
	size_t dstrSize = dstr.Size();
	for (size_t i = 0; i < dstrSize; ++i)
	{
		Insert(dstr.At(i));
	}
}

// Move constructor
DString::DString(DString&& dstring) noexcept
{
	startSym_ = dstring.startSym_;
	endSym_ = dstring.endSym_;
	size_ = dstring.size_;
	dstring.startSym_ = nullptr;
	dstring.endSym_ = nullptr;
	dstring.size_ = 0;
}

// Assignment operator
DString& DString::operator=(const DString& right)
{
	if (&right != this)
	{
		while (size_)
		{
			Remove();
		}
		startSym_ = new DChar;
		endSym_ = startSym_;
		size_t dstrSize = right.Size();
		for (size_t i = 0; i < dstrSize; ++i)
		{
			Insert(right.At(i));
		}
	}
	return *this;
}

// Move assignment operator
DString& DString::operator=(DString&& right) noexcept
{
	while (size_)
	{
		Remove();
	}
	startSym_ = right.startSym_;
	endSym_ = right.endSym_;
	size_ = right.size_;
	right.startSym_ = nullptr;
	right.endSym_ = nullptr;
	right.size_ = 0;
	return *this;
}

// Method that adds a sym to the end of a DString
void DString::Insert(const char &sym)
{
	endSym_->sym = sym;
	endSym_->nextSym = new DChar;
	endSym_->nextSym->previousSym = endSym_;
	endSym_ = endSym_->nextSym;
	size_++;
}

// Method to remove the last element
bool DString::Remove()
{
	bool reply = false;
	if (endSym_->previousSym != nullptr)
	{
		DChar* newPreviousSym = endSym_->previousSym->previousSym;
		delete endSym_->previousSym;
		endSym_->previousSym = newPreviousSym;
		size_--;
		reply = true;
	}
	return reply;
}

// Method returning DString size
size_t DString::Size() const
{
	return size_;
}

// Method returning element by index i
char DString::At(size_t i) const
{
	char reply = 0;
	if (i < size_)
	{
		DChar* current = startSym_;
		for (size_t j = 0; j  < i; j++)
		{
			current = current->nextSym;
		}
		reply = current->sym;
		std::cout << reply;
	}
	return reply;
}


// Operator += overloading
DString& operator+= (DString& left, const DString& right)
{
	size_t dstrSize = right.Size();
	for (size_t i = 0; i < dstrSize; ++i)
	{
		left.Insert(right.At(i));
	}
	return left;
}


// Operator + overloading
DString operator+ (const DString& left, const DString& right)
{
	DString dstring(left);
	dstring += right;
	return dstring;
}
