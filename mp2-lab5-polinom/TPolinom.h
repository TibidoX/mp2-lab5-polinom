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
			if (m > pCurr->val)
				InsCurr(m);
		}
		if (m > pLast->val){
			if (IsEnd()) { InsLast(m); }
		}
	}
};