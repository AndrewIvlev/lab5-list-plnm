template <class T>
class THeadList:public TList<T>{
protected:
	TLink<T> *pHead;
public:
	THeadList() : TList()
	{
		pHead = new TLink<T>;
		pFirst = pLast = pStop = pHead;
		pHead->pNext = pHead;
	}
	~THeadList()
	{
		TList::~TList();
		delete pHead;
	}
	void InsFirst(const T& el)
	{
		TList::InsFirst(el);
		pHead->pNext = pFirst;
	}
/*	void DelFirst()
	{
		TList::DelFirst();
		pHead->pNext = pFirst;
	}
	void DelCurr()
	{
		TList::DelCurr();
		pHead->pNext = pFirst;
	}							*/
};