#include <iostream>
#include "TList.h"
using namespace std;


int main() {
	TList<int> list;

	for(list.Reset(); !list.IsEnd(); list.GoNext() )
		cout << list.GetCurr();
	return 0:
}