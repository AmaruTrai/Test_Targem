#include <iostream>
#include <vector>
#include <algorithm>

#include "Compare.h"
#include "DString.h"

using namespace std;

//	Function for output to the command line vector<DString>
void Print_DStringVector(vector<DString>& dV)
{
	size_t dVSize = dV.size();
	for (size_t i = 0; i < dVSize; ++i)
	{
		cout << "         ";
		size_t sizeD = dV.at(i).Size();
		for (size_t j = 0; j < sizeD; ++j)
		{
			cout << dV.at(i).At(j);
		}
		cout << endl;
	}
}

int main()
{
	vector<DString> dV;

	dV.push_back(DString("Artem"));
	dV.push_back(DString("Jon"));
	dV.push_back(DString("Garold"));
	dV.push_back(DString("Elza"));
	dV.push_back(DString("Gyrold"));

	size_t dVSize = dV.size();

	cout << "This program prints the lines of text entered on the command line in reverse lexicographic order" << endl;
	cout << endl;
	cout << "Example:" << endl;
	Print_DStringVector(dV);

	sort(dV.begin(), dV.end(), Сompare());
	cout << "Result:" << endl;
	Print_DStringVector(dV);

	cout << endl;
	cout << "Enter your lines of text (To complete the entry, enter ^Z or use the combination 'CTRL + Z' on a new line)" << endl;
	cout << endl;

	vector<DString> dVin = { DString ()};
	cout << "         ";
	size_t dVinSize = 0;
	while(!cin.eof())
	{
		if (cin.peek() == '\n')
		{
			cin.get();
			cout << "         ";
			dVin.push_back(DString());
			++dVinSize;
		}
		else
		{
			dVin.at(dVinSize).Insert(cin.get());
		}
	}

	sort(dVin.begin(), dVin.end(), Сompare());

	cout << "Result:" << endl;
	cout << endl;
	Print_DStringVector(dVin);

	return 0;
}
