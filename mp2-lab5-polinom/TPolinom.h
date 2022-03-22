#pragma once
#include "THeadList.h"
#include "TMonom.h"
#include <string>

class TPolinom :public THeadList<TMonom>
{
public:
	TPolinom()
	{
		TMonom m(0, 0, 0, -1);
		pHead->val = m;
	}
	TPolinom(TMonom m)
	{
		TMonom m1(0, 0, 0, -1);
		pHead->val = m1;
		AddMonom(m);
	}
	TPolinom(int c, int x, int y, int z)
	{
		TMonom m1(0, 0, 0, -1);
		pHead->val = m1;
		TMonom m(c, x, y, z);
		AddMonom(m);
	}
	/*{
		TMonom m1(0, 0, 0, -1);
		pHead->val = m1;
		pFirst->val = m;
	}*/
	TPolinom(TPolinom& c)
	{
		for (c.Reset(); !(c.IsEnd()); c.GoNext())
		{
			InsLast(c.pCurr->val);
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

	//TPolinom operator-(TPolinom& pol)
	//{
	//	TPolinom res(*this);
	//	pol.Reset(); res.Reset();
	//	while (!pol.IsEnd())
	//	{
	//		if (res.pCurr->val > pol.pCurr->val)
	//			/*if (pFirst==pLast)
	//			{
	//				res.InsLast(pol.pCurr->val);
	//				pCurr = pLast;
	//				res.pLast->val.c *= -1;
	//				pol.GoNext();
	//			}
	//			else*/
	//				res.GoNext();
	//		else if (res.pCurr->val < pol.pCurr->val)
	//		{
	//			res.InsCurr(pol.pCurr->val);
	//			res.pCurr->val.c *= -1;
	//			pol.GoNext();
	//		}
	//		else
	//		{
	//			res.pCurr->val.c -= pol.pCurr->val.c;
	//			if (res.pCurr->val.c != 0)
	//			{
	//				res.GoNext();
	//				pol.GoNext();
	//			}
	//			else
	//			{
	//				res.DelCurr();
	//				pol.GoNext();
	//			}
	//		}
	//	}
	//	return res;
	//}

	

	TPolinom& operator=(TPolinom& c)
	{
		if (this != &c)
		{
			for (Reset(); !IsEnd();)
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

	bool operator==(TPolinom& c)
	{
		c.Reset();
		for (Reset(); !IsEnd(); GoNext()) {
			if (pCurr->val != c.pCurr->val)
				return false;
			c.GoNext();
		}
		return true;
	}

	bool operator!=(TPolinom& c)
	{
		return !(*this == c);
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

	TPolinom operator-(TPolinom& pol)
	{
		TPolinom res(*this);
		pol = pol * (-1);
		res = *this + pol;
		return res;
	}

	TPolinom operator*(TMonom m)
	{
		TPolinom res(*this);
		for (res.Reset(); !res.IsEnd(); res.GoNext())
		{
			//res = res * m.c;
			res.pCurr->val.c *= m.c;
			res.pCurr->val.x += m.x;
			res.pCurr->val.y += m.y;
			res.pCurr->val.z += m.z;
		}
		return res;
	}

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