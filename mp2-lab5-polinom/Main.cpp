#include <iostream>
#include "TList.h"
#include "TMonom.h"
#include "TPolinom.h"
using namespace std;
void main()
{
	TPolinom pol;
	TMonom m(1, 2, 3, 4);
	pol.AddMonom(m);
	pol.Print();
}