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
	void InsFirst(const T& el) {
		TLink<T> *tmp = new TLink<T>;
		tmp->val = el;
		tmp->pNext = pFirst;
		if ( pFirst == pStop ) {
			pFirst = pLast = pCurr = tmp;
			pos = 0;
		} else { pFirst = tmp; pos++; }
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
	void  InsCur(const T& el) {
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
	void Reset() {
		pCurr = pFirst;
		pos = 0;
		pPrev = pStop;
	}
	void GetNext() {
		pPrev = pCurr;
		pCurr = pCurr->pNext;
		pos++;
	}
	bool IsEnd() { return pCurr == pStop; }
	void DelFirst() {
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
};