template <class T>
class THeadList:public TList<T>{
protected:
	TLink<T> *pHead;
public:
	THeadList() : TList()
	{
		pHead = new TLink<T>;
		pStop = pHead;
		pHead->pNext = pHead;
	}
	~THeadList()
	{
		TList::~TList();
		delete pHead;
	}
	bool IsEnd()
	{
		return pCurr == pStop;
	}
	void InsFirst(const T& el)
	{
		TList::InsFirst(el);
		pHead->pNext = pFirst;
	}
	void InsLast(const T& el)
	{
		TLink<T> *tmp = new TLink<T>;
		tmp->val = el;
		tmp->pNext = pStop;
		if ( pFirst == NULL )
		{
			pHead->pNext = pFirst = pLast = pCurr = tmp;
			pos = 0;
			size = 0;
		}
		else
		{
			pLast->pNext = tmp;
			pLast = tmp;
			pos = size - 1;
		}
		size++;
	}
};
