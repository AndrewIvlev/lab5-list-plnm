# lab5-list-plnm
int size = 20;
	TMonom *Pmonom = new TMonom[size];
	TMonom *Qmonom = new TMonom[size];

	for( int i = 0; i < 4; i++ ){
		Qmonom[i].coeff = ((i+1) * 20) * pow(-1.0, 1+i);
		Qmonom[i].x = i + 1;
		Qmonom[i].y = i + 2;
		Qmonom[i].z = i + 3;
	}
	for( int i = 0; i < 4; i++ ){
		Pmonom[i].coeff = ((i+1) * 10) * pow(-1.0, i);
		Pmonom[i].x = i + 2;
		Pmonom[i].y = i + 3;
		Pmonom[i].z = i + 4;
	}
	TPolinome Q(Qmonom, 4);
	TPolinome P(Pmonom, 4);
	for( Q.Reset(); !Q.IsEnd(); Q.GoNext() )
		cout << Q.GetCurr();
	cout << endl;
	for( P.Reset(); !P.IsEnd(); P.GoNext() )
		cout << P.GetCurr();
	cout << endl;
	Q = P * (-1.0);
	for( Q.Reset(); !Q.IsEnd(); Q.GoNext() )
		cout << Q.GetCurr();
	cout << endl;
	//P += Q;
	Q += P;cout << "/////////////////////////////////////////////////\n";
	for( P.Reset(); !P.IsEnd(); P.GoNext() )
		cout << P.GetCurr();
	cout << endl;
