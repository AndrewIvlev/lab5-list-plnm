using namespace std;
ostream& operator<<(ostream &out, TMonom &tm)
{
	if( tm.coeff < 0 );
	else
	{
		if ( tm.coeff > 0 ) out << '+';
		else return out;
	}
	out << tm.coeff << "x^"
		<< tm.x << "y^"
		<< tm.y << "z^"
		<< tm.z;
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
		pHead->val.z = -1;
	}
	TPolinome(const TMonom *tm, int size):THeadList()
	{
		pHead->val.coeff = 0;
		pHead->val.z = -1;
		for(int i = 0; i < size; i++)
			InsLast(tm[i]);
	}
	void InsByOrder(TMonom& tm){
		for ( Reset(); !IsEnd(); GoNext() )
		{
			if ( this->pCurr->val == tm ){
				if ( ( this->pCurr->val.coeff += tm.coeff ) == 0 )
				{
					this->DelCurr();
					return;
				}
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
	/*TPolinome& operator+(TPolinome &q)
	{

	}*/
	/*void operator+=(const TPolinome& q){
		for (q.Reset(); !q.IsEnd(); q.GoNext())
			InsByOrder(q.pCurr->val);
	}*/
	void operator+=(TPolinome &q){
		q.Reset();
		Reset();
		while ( !q.IsEnd() && !IsEnd() )
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
					GoNext();
				}
				else
				{
					InsCurr(q.pCurr->val);
					q.GoNext();
				}
			}
		}
		if(!q.IsEnd()) InsCurr(q.pCurr->val);
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
		for( P.Reset(); !P.IsEnd(); P.GoNext() )
			out << P.GetCurr();
		return out;
	}
};