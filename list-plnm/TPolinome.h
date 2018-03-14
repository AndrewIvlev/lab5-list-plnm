using namespace std;
ostream& operator<<(ostream &out, TMonom &tm)
{
	if ( tm.coeff > 0 ) out << '+';
	if (tm.coeff == 0) return out;
	else
	{
		out << tm.coeff;
		if (tm.x != 0) out << "x^" << tm.x;
		if (tm.y != 0) out << "y^" << tm.y;
		if (tm.z != 0) out << "z^" << tm.z;
	}
	return out;
}
istream& operator>>(istream &in, TMonom &tm)
{
	in >> tm.coeff >> tm.x
		>> tm.y >> tm.z;

	return in;
}
bool operator<(const TMonom &t1, const TMonom &t2)
{
	if (t1.x * 100 + t1.y * 10 + t2.z < t2.x * 100 + t2.y * 10 * t2.z) return true;
	else return false;
}
bool operator==(const TMonom &t1, const TMonom &t2)
{
	if ( t1.x == t2.x && t1.y == t2.y && t1.z == t2.z ) return true;
	else return false;
}

class TPolinome : public THeadList<TMonom>{
public:
	TPolinome():THeadList(){
		pHead->val.coeff = 0;
		pHead->val.x = 0;
		pHead->val.y = 0;
		pHead->val.z = -1;
	}
	TPolinome(const TMonom *tm, int size):THeadList()
	{
		pHead->val.coeff = 0;
		pHead->val.x = 0;
		pHead->val.y = 0;
		pHead->val.z = -1;
		for (int i = 0; i < size; i++)
			InsLast(tm[i]);
	}
	void ClearTPolinome()
	{
		for ( Reset(); !IsEnd(); GoNext() )
			DelFirst();
	}
	TPolinome& operator=(TPolinome& P)
	{
		ClearTPolinome();
		for (P.Reset(); !P.IsEnd(); P.GoNext())
			InsLast(P.pCurr->val);
		return *this;
	}
	void InsByOrder(TMonom& tm)
	{
		for ( Reset(); !IsEnd(); GoNext() )
		{
			if ( this->pCurr->val == tm )
			{
				if ( ( this->pCurr->val.coeff += tm.coeff ) == 0 )
				{
					this->DelCurr();
					return;
				}
				return;
			}
			if ( this->pCurr->val < tm )
			{
				InsCurr(tm);
				return;
			}
		}
		InsLast(tm);
	}
	TPolinome& operator*(const double c)
	{
		for (Reset(); !IsEnd(); GoNext())
			pCurr->val.coeff *= c;
		return *this;
	}
	void operator*=(const double c)
	{
		for (Reset(); !IsEnd(); GoNext())
			pCurr->val.coeff *= c;
	}
	void operator+=(TPolinome &q)
	{
		for (q.Reset(); !q.IsEnd();q.GoNext())
			InsByOrder(q.pCurr->val);
	}
	/*void operator+=(TPolinome &q)
	{
		q.Reset();
		Reset();
		while ( !q.IsEnd() || !IsEnd() )
		{
			if ( pCurr->val == q.pCurr->val)
			{
				pCurr->val.coeff += q.pCurr->val.coeff;
				if ( pCurr->val.coeff == 0 )
				{
					DelCurr();
					q.GoNext();
				} 
				else 
				{
					GoNext();
					q.GoNext();
				}
			} 
			else 
			{
				if ( pCurr->val < q.pCurr->val )
				{
					InsCurr(q.pCurr->val);
					q.GoNext();
				}
				else
				{
					GoNext();
				}
			}
		}
		if(!q.IsEnd())
			InsCurr(q.pCurr->val);
	}*/
	void operator+=(TMonom &tm)
	{
		Reset();
		while (!IsEnd())
		{
			if ( pCurr->val == tm)
			{
				pCurr->val.coeff += tm.coeff;
				if ( pCurr->val.coeff == 0 )
				{
					DelCurr();
					return;
				}
				else return;
			} 
			if ( tm < pCurr->val )
			{
				InsCurr(tm);
				return;
			}
			GoNext();
		}
		InsLast(tm);
	}
	friend istream& operator>>(istream &in, TPolinome &P)
	{
		while( in >> P.pCurr->val.coeff )
		{
			in >> P.pCurr->val.x
				>> P.pCurr->val.y 
				>> P.pCurr->val.z;
		}
		return in;
	}
	friend ostream& operator<<(ostream &out, TPolinome &P)
	{
		/*if(P.pFirst->val.coeff == 0)
			out << "0";
		else
		{*/
			for( P.Reset(); !P.IsEnd(); P.GoNext() )
				out << P.GetCurr();
		//}
		return out;
	}
};