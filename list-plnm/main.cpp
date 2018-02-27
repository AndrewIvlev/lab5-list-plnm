#include <iostream>
//#include <string>
#include <cmath>
#include "TList.h"
#include "THeadList.h"
#include "TPolinome.h"
using namespace std;

void Menu()
{
	cout << "****POLINOME****\n";
	cout << "0.Initialization\n";
	cout << "1.Polynom Out\n";
	cout << "2.Add Monom\n";
	cout << "3.P*const\n";
	cout << "4.P+Q\n";
	cout << "5.Exit\n";
}
int main(){
	int r = 0;
	TPolinome *P, *Q;
	TMonom *Qmonom, *Pmonom;
	int Psize = 0, Qsize = 0;
	while(r!=5){
		Menu();
		cin >> r;
		switch(r){
			case 0: system("cls");
				cout << "Enter Size of Polynomial P: ";
				cin >> Psize;

				Pmonom = new TMonom[Psize];

				cout << "Initialize Polinome P\nP(x)=";
				for (int i = 0; i < Psize; i++)
					cin >> Pmonom[i];

				cout << "Enter Size of Polynomial Q: ";
				cin >> Psize;

				Qmonom = new TMonom[Qsize];

				cout << "Initialize Polinome Q\nQ(x)=";
				for (int i = 0; i < Qsize; i++)
					cin >> Qmonom[i];
				Q(Qmonom, Qsize);
				P(Pmonom, Psize);
				break;
			case 1: system("cls");
				for( P.Reset(); !P.IsEnd(); P.GoNext() )
					cout << P.GetCurr();
				cout << endl;
				for( Q.Reset(); !Q.IsEnd(); Q.GoNext() )
					cout << Q.GetCurr();
				cout << endl;
				break;
			case 2: system("cls"); cout << "Add to Q or to P?";
				if (cin >> ch == "q"){
					cout << "Enter Monom: ";
					cin >> Qmonom[0];
					Q.InsByOrder(Qmonom[0]);
				}
				else {
					cout << "Enter Monom: ";
					cin >> Pmonom[0];
					P.InsByOrder(Pmonom[0]);
				}
				break;
			case 3: system("cls");
				break;
			case 4: system("cls"); 
				break;
			case 5: break; break;
			default: system("cls"); r = -1;
				cout << "Invalid Entry\n"; break;
		}
	}

	return 0;
}
