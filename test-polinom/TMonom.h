#pragma once
#include <iostream>

using namespace std;
struct TMonom
{
	double c;
	int x, y, z;

	TMonom(double _c = 0, int _x = 0, int _y = 0, int _z = 0)
	{
		c = _c;
		x = _x;
		y = _y;
		z = _z;
	}
	bool operator==(const TMonom& m) {return ((x == m.x) && (y == m.y) && (z == m.z));}
	bool operator>(const TMonom& m)
	{
		if (x != m.x)
			return (x > m.x);
		else if (y != m.x)
			return (y > m.y);
		else if (z != m.z)
			return (z > m.z);
		else return false;
	}
	bool operator<(const TMonom& m)
	{
		if (x != m.x)
			return (x < m.x);
		else if (y != m.x)
			return (y < m.y);
		else if (z != m.z)
			return (z < m.z);
		else return false;
	}
	friend ostream& operator<<(ostream& os, const TMonom& m)
	{
		os << m.c << "x^" << m.x << "y^" << m.y << "z^" << m.z << " ";
		return os;
	}
};