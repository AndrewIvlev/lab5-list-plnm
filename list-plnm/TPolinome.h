#include "THeadList.h"

struct TMonom{
	double coeff;
	int degs;
};
bool operator<(const TMonom &t1, const TMonom &t2)
{
	if (t1.degs < t2.degs) return true;
	else return false;
		/*if (t1.coeff < t2.coeff) return true;
		else return false;*/
}
bool operator==(const TMonom &t1, const TMonom &t2)
{
	if (t1.degs == t2.coeff) return true;
	else return false;
}
class TPolinome::public THeadList<TMonom>{
	public:
		TPolinome(){
		}
		void InputPol(){
			string 
		friend istream& operator>>(istream &in, TPolinome &P)
		{
			return in;
		}
		friend ostream& operator<<(ostream &out, const TPolinome &P)
		{
			return out;
		}
};