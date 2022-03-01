#pragma once
#include "TList.h"
template <class T>
class THeadList:public TList<T>
{
protected:
	TNode<T>* pHead;
public:
	THeadList()
	{
		len = 0;
//		pCurr = new TNode<T>;
//		pFirst = new TNode<T>;
//		pPrev = new TNode<T>;
//		pLast = new TNode<T>;
//		pStop = new TNode<T>;

		pHead = new TNode<T>;

		pHead->pNext = pHead;
		pStop = pHead;
		pCurr = pPrev = pLast = pFirst = pStop;
	}
	~THeadList()
	{
		pCurr = pFirst;
		while (pCurr != pStop)
		{
			TNode<T>* pDel = pCurr;
			pPrev = pCurr;
			pCurr = pCurr->pNext;
			delete pDel;
		}
		delete pHead;
		pFirst = pStop;
	}
	void InsFirst(T v)
	{
		TList::InsFirst(v);
		pHead->pNext = pFirst;
	}
	void DelFirst()
	{
		TList::DelFirst();
		pHead->pNext = pFirst;
	}
	
};