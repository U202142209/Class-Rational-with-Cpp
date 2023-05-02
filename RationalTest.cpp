#include <iostream>
#include "Rational.h"
using namespace std;

int main()
{
	// 有理数测试
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