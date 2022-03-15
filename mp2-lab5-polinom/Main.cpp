#include <iostream>
#include "TList.h"
#include "TMonom.h"
#include "TPolinom.h"
using namespace std;
void main()
{
	TPolinom pol;
	TMonom m(1, 1, 3, 4);
	TMonom n(2, 2, 2, 3);
	TMonom l(3, 8, 9, 6);
	pol.AddMonom(m);
	pol.AddMonom(n);
	pol.AddMonom(l);
	TPolinom np;
	np.AddMonom(m);
	np.AddMonom(n);
	np.AddMonom(m);
	TPolinom p = np - pol;
	//cout << p;
	p = p * 2;
	cout << p;
}