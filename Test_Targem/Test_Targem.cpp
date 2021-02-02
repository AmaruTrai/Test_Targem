#include <iostream>
#include <vector>
#include "DString.h"

int main()
{
	DString a("Hcehi");
	char ch[5] = { 'T','E','l','l' ,'e'};
	DString b(ch,5);
	DString e;

	e = a;
	std::cout << std::endl;
	e = b;
	std::cout << std::endl;
	e = (a + b);
	std::cout << std::endl;
	e += (a + b);
	std::cout << std::endl;
	DString c(std::move(e));

	while (true)
	{

	}
	return 0;
}
