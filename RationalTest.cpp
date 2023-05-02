#include <iostream>
#include "Rational.h"
#include "Matrix.h"
using namespace std;

int main()
{
	// ÓĞÀíÊı²âÊÔ
	Rational r1(1.5);
	Rational r2(7.5);
	cout << r1 + 1 << endl;
	cout << r1 - 1 << endl;
	cout << r1 * -2 << endl;
	cout << r1 / 2 << endl;

	cout << r1 + r2 << endl;
	cout << r1 - r2 << endl;
	cout << r1 * r2 << endl;
	cout << r1 / r2 << endl;
	return 0;
}