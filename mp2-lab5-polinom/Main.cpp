#include <iostream>
#include "TList.h"
#include "TMonom.h"

using namespace std;
void main()
{
	TMonom m(2,1,2,3);
	TList<TMonom> pol;
	pol.InsFirst(m);
	cout << pol.GetCurrVal();
}