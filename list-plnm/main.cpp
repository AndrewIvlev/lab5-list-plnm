#include <iostream>
#include <cmath>
#include "TList.h"
#include "THeadList.h"
#include "TPolinome.h"
using namespace std;

void Menu()
{
	cout << "----------------\n";
	cout << "****POLINOME****\n";
	cout << "----------------\n";
	cout << "1.Initialization\n";
	cout << "2.Polynom Out\n";
	cout << "3.Add Monom\n";
	cout << "4.Mult on const\n";
	cout << "5.P + Q\n";
	cout << "6.Exit\n";
}
int main(){
	char ch='q';
	int c = 0, r = 0;
	TPolinome P, Q, S;
	int Psize = 0, Qsize = 0;
	TMonom *Qmonom = new TMonom[66];
	TMonom *Pmonom = new TMonom[66];

	while (r != 6)
	{
		Menu();
		cin >> r;
		switch(r){
			case 1: system("cls");

				P.ClearTPolinome();
				Q.ClearTPolinome();

				cout << "Enter Size of Polynomial P: ";
				cin >> Psize;
				cout << "Initialize Polinome P\nP(x)=";
				for (int i = 0; i < Psize; i++)
					cin >> Pmonom[i];
				for (int i = 0; i < Psize; i++)
					P += Pmonom[i];

				cout << "Enter Size of Polynomial Q: ";
				cin >> Qsize;
				cout << "Initialize Polinome Q\nQ(x)=";
				for (int i = 0; i < Qsize; i++)
					cin >> Qmonom[i];
				for (int i = 0; i < Qsize; i++)
					Q += Qmonom[i];
				break;

			case 2: system("cls");
				cout << "P(x)=" << P << endl
					<< "Q(x)=" << Q << endl;
				break;

			case 3: system("cls"); cout << "Add to Q or to P?\nInput 'q' if Q, 'p' if P\n";
				cin >> ch;
				if (ch == 'q')
				{
					cout << "Enter Monom: ";
					cin >> Qmonom[0];
					Q += Qmonom[0];
				}
				else
				{
					cout << "Enter Monom: ";
					cin >> Pmonom[0];
					P += Pmonom[0];

				}
				break;

			case 4: system("cls"); cout << "Multiply P or Q??\nInput 'q' if Q, 'p' if P\n";
				cin >> ch;
				cout << "Enter const: ";
				cin >> c;
				if (ch == 'q')
				{
					Q *= c;
					cout << Q << endl;
				}
				else
				{
					P *= c;
					cout << P << endl;
				}

				break;

			case 5: system("cls");
				S = P;
				S += Q;
				cout << "P(x)=" << P << endl
					<< "Q(x)=" << Q << endl;
				cout << "S(x)=P(x)+Q(x)\nS(x)=" << S << endl;
				break;

			case 6: break;

			default: system("cls"); r = -1;
				cout << "Invalid Entry\n"; break;
		}
	}

	return 0;
}
