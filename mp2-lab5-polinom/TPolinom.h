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
		if (m > pLast->val)
		{
			if(IsEmpty())
			{
				InsFirst(m);
			}
			else
			{
				if (IsEnd())
				{
					InsLast(m);
				}
			}
		}
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
	void Print()
	{
		for (Reset(); !IsEnd(); GoNext())
			cout << pCurr->val;
	}
};