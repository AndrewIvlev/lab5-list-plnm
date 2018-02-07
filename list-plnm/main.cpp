#include <iostream>
#include "TList.h"
using namespace std;


int main() {
	TPolinome P;
	string strpol;

	cin >> strpol;
	P.ReadPol(strpol);

	return 0;
}


	/*TList<int> list;
	int i = 0;

	while ( cin >> i )
	list.InsSort(i);

		for(list.Reset(); !list.IsEnd(); list.GoNext() )
		cout << list.GetCurr() << " ";
	cout << endl;
	cout << 123 / 100 << endl;
	cout << 123 % 100 / 10 << endl;
	cout << 123 % 10 << endl;*/