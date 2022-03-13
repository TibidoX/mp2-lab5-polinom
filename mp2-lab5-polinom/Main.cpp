#include <iostream>
#include "TList.h"
#include "TMonom.h"
#include "TPolinom.h"
using namespace std;
void main()
{
	TPolinom pol;
	TMonom m(1, 2, 3, 4);
	TMonom n(2, 2, 3, 4);
	TMonom l(9, 8, 9, 6);
	pol.AddMonom(m);
	pol.AddMonom(n);
	pol.AddMonom(l);
	//pol.Print();
	TPolinom np(pol);
	TPolinom p = np + pol;
	p.Print();
}