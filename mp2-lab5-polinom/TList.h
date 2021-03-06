#pragma once
#include "TNode.h"

template <class T>
class TList
{
protected:
	TNode<T>* pFirst, * pCurr, * pPrev, * pLast, * pStop;
	int len;
public:
	TList()
	{
		len = 0;
		pStop = nullptr;
		pCurr = pFirst = pPrev = pLast = pStop;
	}
	~TList()
	{
		pCurr = pFirst;
		while (pCurr != pStop)
		{
			TNode<T>* pDel = pCurr;
			pPrev = pCurr;
			pCurr = pCurr->pNext;
			delete pDel;
		}
	}
	bool IsEmpty() { return(pFirst == pStop); }
	T GetCurrVal()
	{
		if (pCurr != pStop)
			return pCurr->val;
		else throw - 1;
	}

	void InsFirst(T v)
	{
		TNode<T>* p = new TNode<T>;
		p->val = v;
		p->pNext = pFirst;
		pFirst = p;
		len++;
		if (len == 1)
			pLast = p;
	}
	void InsLast(T v)
	{
		TNode<T>* p = new TNode<T>;
		p->val = v;
		p->pNext = pStop;
		if (pLast != pStop)
			pLast->pNext = p;
		else pFirst = p;
		pLast = p;
		len++;
	}
	void InsCurr(T v)
	{
		if (pCurr == pFirst) {
			InsFirst(v);
			pPrev = pStop;
			pCurr = pFirst;
		}
		else if (pPrev == pLast) {
			InsLast(v);
			pPrev = pLast;
		}
		else {
			TNode<T>* p = new TNode<T>(v, pCurr);
			if (pPrev != pStop)
			{
				pPrev->pNext = p;
			}
			pCurr = p;
			len++;
		}
		//if (pCurr == pFirst) {
		//	InsFirst(v);
		//	//pCurr = pFirst;
		//}
		//else if (pPrev == pLast) {
		//	InsLast(v);
		//	//pCurr = pLast;//
		//}
		//else
		//{
		//	TNode<T>* p = new TNode<T>(v, pCurr);
		//	pPrev->pNext = p;
		//	pCurr = p;
		//	len++;
		//}
	}
	void DelFirst()
	{
		if (pFirst != pStop)
		{
			TNode<T>* pDel = pFirst;
			pFirst = pFirst->pNext;
			pCurr = pFirst;
			delete pDel;
			len--;
			if (len == 0) pLast = pStop;
		}
	}
	void DelCurr()
	{
		if (pCurr != pStop)
			if (pCurr == pFirst) {
				DelFirst();
				//pCurr = pFirst;
			}
			else
			{
				TNode<T>* pDel = pCurr;
				pCurr = pCurr->pNext;
				pPrev->pNext = pCurr;
				delete pDel;
				len--;
			}
		else throw - 1;
	}
	void Reset() { pCurr = pFirst; pPrev = pStop; }
	void GoNext() 
	{
		if (pCurr != pStop) { 
			pPrev = pCurr;
			pCurr = pCurr->pNext; 
		} 
	}

	bool IsEnd() { return(pCurr == pStop); }
};