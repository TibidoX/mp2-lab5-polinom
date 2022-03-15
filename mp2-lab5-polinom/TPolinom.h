#pragma once
#include "THeadList.h"
#include "TMonom.h"

class TPolinom :public THeadList<TMonom>
{
public:
	TPolinom()
	{
		TMonom m(0, 0, 0, -1);
		pHead->val = m;
	}
	TPolinom(TPolinom& c)
	{
		for (c.Reset(); !(c.IsEnd()); c.GoNext())
		{
			InsLast(c.pCurr->val);
			//pHead = pHead->pNext;
		}
	}
	void AddMonom(TMonom& m)
	{

		for (Reset(); !IsEnd(); GoNext())
		{
			if (m == pCurr->val)
			{
				pCurr->val.c += m.c;
				if (pCurr->val.c == 0) DelCurr();
				break;
			}
			if ((m > pCurr->val))
			{
				InsCurr(m);
				break;
			}
		}

		if (IsEnd()) InsLast(m);

		//if (IsEmpty())
		//{
		//	InsFirst(m);
		//	//if (pCurr->val.c == 0) DelCurr();
		//}

		//if (pLast->val>m)
		//{
		//		if (IsEnd())
		//		{
		//			InsLast(m);
		//			//if (pCurr->val.c == 0) DelCurr();
		//		}
		//}
	}
	TPolinom operator+(TPolinom& pol)
	{
		TPolinom res(*this);
		pol.Reset(); res.Reset();
		while (!pol.IsEnd())
		{
			if (res.pCurr->val > pol.pCurr->val)
				res.GoNext();
			else if (res.pCurr->val < pol.pCurr->val)
			{
				res.InsCurr(pol.pCurr->val);
				pol.GoNext();
			}
			else
			{
				res.pCurr->val.c += pol.pCurr->val.c;
				if (res.pCurr->val.c != 0)
				{
					res.GoNext();
					//pol.GoNext();
				}
				else
				{
					res.DelCurr();
					//pol.GoNext();
				}
				pol.GoNext();
			}
		}
		return res;
	}

	TPolinom operator-(TPolinom& pol)
	{
		TPolinom res(*this);
		pol.Reset(); res.Reset();
		while (!pol.IsEnd())
		{
			if (res.pCurr->val > pol.pCurr->val)
				/*if (pFirst==pLast)
				{
					res.InsLast(pol.pCurr->val);
					pCurr = pLast;
					res.pLast->val.c *= -1;
					pol.GoNext();
				}
				else*/
					res.GoNext();
			else if (res.pCurr->val < pol.pCurr->val)
			{
				res.InsCurr(pol.pCurr->val);
				res.pCurr->val.c *= -1;
				pol.GoNext();
			}
			else
			{
				res.pCurr->val.c -= pol.pCurr->val.c;
				if (res.pCurr->val.c != 0)
				{
					res.GoNext();
					pol.GoNext();
				}
				else
				{
					res.DelCurr();
					pol.GoNext();
				}
			}
		}
		return res;
	}

	TPolinom& operator=(TPolinom& c)
	{
		if (this != &c)
		{
			for (Reset(); !IsEnd(); GoNext())
			{
				DelCurr();
			}
			for (c.Reset(); !c.IsEnd(); c.GoNext())
			{
				InsLast(c.pCurr->val);
			}
		}
		return *this;
	}

	TPolinom operator*(double a)
	{
		TPolinom res(*this);
		for (res.Reset(); !res.IsEnd(); res.GoNext())
		{
			res.pCurr->val.c *= a;
		}
		return res;
	}

	/*void Print()
	{
		for (Reset(); !IsEnd(); GoNext())
			if (pCurr->pNext == pStop)
				cout << pCurr->val;
			else 
				cout << pCurr->val << "+ ";
	}*/

	friend ostream& operator<<(ostream& os, TPolinom& p)
	{
		if (p.IsEmpty())
			os << 0;
		for (p.Reset(); !p.IsEnd(); p.GoNext())
			//if (p.pCurr==p.pLast)
			if (p.pCurr->pNext == p.pStop)
				os << p.pCurr->val;
			else
				os << p.pCurr->val << "+ ";
		return os;
	}
};