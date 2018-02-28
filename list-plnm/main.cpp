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
	char ch='q';
	int c = 0, r = 0;
	TPolinome P, Q, S;
	int Psize = 50, Qsize = 50;
	TMonom *Qmonom = new TMonom[Qsize];
	TMonom *Pmonom = new TMonom[Psize];;

	while(r!=5){
		Menu();
		cin >> r;
		switch(r){
			case 0: system("cls");
				cout << "Enter Size of Polynomial P: ";
				cin >> Psize;

				cout << "Initialize Polinome P\nP(x)=";
				for (int i = 0; i < Psize; i++)
					cin >> Pmonom[i];
				P.Reset();
				for (int i = 0; !P.IsEnd(); P.GoNext()){
					P.InsByOrder(Pmonom[i]);
					i++;
				}

				cout << "Enter Size of Polynomial Q: ";
				cin >> Qsize;

				cout << "Initialize Polinome Q\nQ(x)=";
				for (int i = 0; i < Qsize; i++)
					cin >> Qmonom[i];
				Q.Reset();
				for (int i = 0; !Q.IsEnd(); Q.GoNext()){
					Q.InsByOrder(Qmonom[i]);
					i++;
				}
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
			case 3: system("cls"); cout << "Enter const: ";
				cin >> c;
				P = P * c;
				for( P.Reset(); !P.IsEnd(); P.GoNext() )
					cout << P.GetCurr();
				cout << endl;
				break;
			case 4: system("cls"); 	S = P + Q;
				for( S.Reset(); !S.IsEnd(); S.GoNext() )
					cout << S.GetCurr();
				cout << endl;
				break;
			case 5: break; break;
			default: system("cls"); r = -1;
				cout << "Invalid Entry\n"; break;
		}
	}

	return 0;
}
