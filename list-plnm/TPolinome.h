using namespace std;
struct TMonom{
	double coeff;
	int x, y, z;
};

bool operator<(const TMonom &t1, const TMonom &t2)
{
	if (t1.x < t2.x) return true;
	else {
		if ( t1.y < t2.y ) return true;
		else { 
			if ( t2.z < t2.z ) return true;
		}
	}
	return false;
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
	/*void operator+=(const TPolinome& q){
		for (q.Reset(); !q.IsEnd(); q.GoNext())
			InsByOrder(q.pCurr->val);
	}*/
	void operator+=(TPolinome &q){
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
				else GoNext();
			}
		}
	}
	friend istream& operator>>(istream &in, TPolinome &P)
	{
		while(	in >> P.pCurr->val.coeff )
		{
			in >> P.pCurr->val.x
				>> P.pCurr->val.y 
				>> P.pCurr->val.z;
		}
		return in;
	}
	friend ostream& operator<<(ostream &out, TPolinome &P)
	{
		for (P.Reset(); !P.IsEnd(); P.GoNext())
		{
			out << P.pCurr->val.coeff << 'x^'
				<< P.pCurr->val.x << 'y^'
				<< P.pCurr->val.y << 'z^'
				<< P.pCurr->val.z;
		}
		return out;
	}
};