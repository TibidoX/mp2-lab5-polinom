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
		pCurr = pFirst = pPrev = pLast = pStop = nullptr;
	}
	~TList()
	{
		while (pFirst != NULL)
		{
			TNode<T>* pDel = pFirst;
			pFirst = pFirst->pNext;
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
	void SetCurrVal(T v) { pCurr->val = v; }
	void InsFirst(T v)
	{
		TNode<T>* p = new TNode<T>(v,pFirst);
		p->val = v;
		p->pNext = pFirst;
		pFirst = p;
		pCurr = p;
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
		if (pCurr == pFirst) InsFirst(v);
		else if (pCurr == pLast) InsLast(v);
		else
		{
			TNode<T>* p = new TNode<T>(v, pCurr);
			pPrev->pNext = p;
			pCurr = p;
			len++;
		}
	}
	void DelCurr()
	{
		if (pCurr == pFirst)
		{
			if (pFirst != nullptr) {
				TNode<T>* pDel = pFirst;
				pFirst = pFirst->pNext;
				delete[] pDel;
				len--;
			}
		}
		else
		{
			TNode<T>* pDel = pCurr;
			pCurr = pCurr->pNext;
			pPrev->pNext = pCurr;
			delete[] pDel;
			len--;
		}
	}
};