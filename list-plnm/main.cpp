#include <iostream>
#include "TList.h"
using namespace std;


int main() {
	TList<int> list;
	int i = 0;

	while ( cin >> i )
		list.InsSort(i);

	for(list.Reset(); !list.IsEnd(); list.GoNext() )
		cout << list.GetCurr() << " ";
	cout << endl;

	return 0;
}