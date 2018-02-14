template <class T>
struct TLink {
	T val;
	TLink *pNext;
};

template <class T>
class TList {
	TLink<T> *pFirst, *pPrev, *pCurr, *pStop, *pLast;
	int size, pos;
public:
	TList() { pFirst = pCurr = pLast = pStop = NULL; pos = -1; size = 0; }
	void Reset() {
		pCurr = pFirst;
		pos = 0;
		pPrev = pStop;
	}
	void GoNext() {
		pPrev = pCurr;
		pCurr = pCurr->pNext;
		pos++;
	}
	T GetCurr() {
		return pCurr->val;
	}
	bool IsEnd() { return pCurr == pStop; }
	virtual void DelFirst() {
		if ( size == 1 ) {
			delete pFirst;
			pFirst = pCurr = pLast = pPrev = pStop;
		} else {
			TLink<T> *pOld = pFirst;
			pFirst = pFirst->pNext;
			delete pOld;
		} size--;
		if ( pos > 0 ) pos--;
	}
	virtual void DelCurr()
	{
		if ( size == 1 )
			DelFirst();
		else {
			if ( pCurr == pLast ) DelLast();
			else GoNext();
		}
	}
	virtual void InsFirst(const T& el) {
		TLink<T> *tmp = new TLink<T>;
		tmp->val = el;
		tmp->pNext = pFirst;
		if ( pFirst == pStop ) {
			pFirst = pLast = pCurr = tmp;
			tmp->pNext = pStop;
		} else { pPrev = pFirst = tmp; pos++;}
		size++;
	}
	void InsLast(const T& el) {
		TLink<T> *tmp = new TLink<T>;
		tmp->val = el;
		tmp->pNext = pStop;
		if ( pFirst == pStop ) {
			pFirst = pLast = pCurr = tmp;
			pos = 0;
		} else { pLast->pNext = tmp; pLast = tmp; }
		size++;
	}
	void  InsCurr(const T& el) {
		if ( pCurr == pFirst ) InsFirst(el);
		else {
			if ( pCurr == pStop ) InsLast(el);
			else {
				TLink<T> *tmp = new TLink<T>;
				tmp->val = el;
				tmp->pNext = pCurr;
				pPrev->pNext = tmp;
				pCurr = tmp;
				size++;
			}
		}
	}
	void InsSort(const T& el) {
		if ( pFirst == pStop || el > pFirst->val ) { InsFirst(el); return ;}
		if ( el < pLast->val ) { InsLast(el); return;}
		for ( Reset(); !IsEnd(); GoNext() ) {
			if ( pCurr->val < el ) { InsCurr(el); return; }
		}
	}
};