#include <iostream>
#include <string>
#include <cstdlib>
#include "Rational.h"

using namespace std;
// 约分
void Rational::simply()//辗转相除法求最大公约数化简
{
	int a = fenzi, b = fenmu;
	while (b) {
		int mod = a % b;
		a = b;
		b = mod;
	}

	fenzi /= a;
	fenmu /= a;
}
// 是否为负数<0
bool Rational::negative() const
{
	return (fenzi < 0 || fenmu < 0);
}
// 构造方法
Rational::Rational(int numerator, int denominator)
{
	fenzi = numerator;
	fenmu = denominator;
	simply();//确保任意路径得到的有理数类对象均是最简形式
}
Rational::Rational(const double n)
{
	double numerator = n, denominator = 1;

	while ((int)numerator != numerator) {
		numerator *= 10;
		denominator *= 10;
	}

	fenzi = numerator, fenmu = denominator;
	simply();//确保任意路径得到的有理数类对象均是最简形式
}
// 拷贝方法
Rational::Rational(const Rational& ra) : fenzi(ra.fenzi), fenmu(ra.fenmu) {}
// 重载赋值运算符=
Rational& Rational::operator =(const Rational& ra)
{
	fenzi = ra.fenzi, fenmu = ra.fenmu;
	return *this;
}
Rational& Rational::operator =(const double& n)
{
	Rational tmp(n);
	*this = tmp;
	return *this;
}
// 有理数与有理数的运算+-*/
Rational Rational::operator +(const Rational& ra)
{
	int numerator = fenzi * ra.fenmu + ra.fenzi * fenmu;
	int denominator = fenmu * ra.fenmu;

	return Rational(numerator, denominator);
}
Rational Rational::operator -(const Rational& ra)
{
	int numerator = fenzi * ra.fenmu - ra.fenzi * fenmu;
	int denominator = fenmu * ra.fenmu;

	return Rational(numerator, denominator);
}
Rational Rational::operator *(const Rational& ra)
{
	int numerator = fenzi * ra.fenzi;
	int denominator = fenmu * ra.fenmu;

	return Rational(numerator, denominator);
}
Rational Rational::operator /(const Rational& ra)
{
	if (ra.fenzi == 0) {
		// 抛出异常
		throw exception("除数为0了！");
		cout << "除数为0了！" << endl;
		exit(1);
	}
	int numerator = fenzi * ra.fenmu;
	int denominator = fenmu * ra.fenzi;

	return Rational(numerator, denominator);
}
Rational& Rational::operator +=(const Rational& ra)
{
	Rational tmp = *this + ra;
	*this = tmp;
	return *this;
}
Rational& Rational::operator -=(const Rational& ra)
{
	Rational tmp = *this - ra;
	*this = tmp;
	return *this;
}
Rational& Rational::operator *=(const Rational& ra)
{
	Rational tmp = *this * ra;
	*this = tmp;
	return *this;
}
Rational& Rational::operator /=(const Rational& ra)
{
	Rational tmp = *this / ra;
	*this = tmp;
	return *this;
}
// 重载double浮点数与有理数的运算+-*/
Rational Rational::operator +(const double& n)
{
	Rational tmp(n);
	return *this + tmp;
}
Rational Rational::operator -(const double& n)
{
	Rational tmp(n);
	return *this - tmp;
}
Rational Rational::operator *(const double& n)
{
	Rational tmp(n);
	return *this * tmp;
}
Rational Rational::operator /(const double& n)
{
	Rational tmp(n);
	return *this / tmp;
}
Rational operator +(const double& n, const Rational& ra)
{
	Rational tmp(n);
	return tmp + ra;
}
Rational operator -(const double& n, const Rational& ra)
{
	Rational tmp(n);
	return tmp - ra;
}
Rational operator *(const double& n, const Rational& ra)
{
	Rational tmp(n);
	return tmp * ra;
}
Rational operator /(const double& n, const Rational& ra)
{
	Rational tmp(n);
	return tmp / ra;
}
Rational& Rational::operator +=(const double& ra)
{
	Rational tmp(ra);
	*this += tmp;
	return *this;
}
Rational& Rational::operator -=(const double& ra)
{
	Rational tmp(ra);
	*this -= tmp;
	return *this;
}
Rational& Rational::operator *=(const double& ra)
{
	Rational tmp(ra);
	*this *= tmp;
	return *this;
}
Rational& Rational::operator /=(const double& ra)
{
	Rational tmp(ra);
	*this /= tmp;
	return *this;
}
// 有理数转化为浮点数
Rational::operator double()
{
	return (double)fenzi / fenmu;
}
// 有理数与整数int的计算+-*/
Rational Rational::operator +(const int& n) {
	Rational tmp((double)n);
	return *this + tmp;
}
Rational Rational::operator -(const int& n) {
	Rational tmp((double)n);
	return *this - tmp;
}
Rational Rational::operator *(const int& n) {
	Rational tmp((double)n);
	return *this * tmp;
}
Rational Rational::operator /(const int& n) {
	Rational tmp((double)n);
	return *this / tmp;
}
Rational operator +(const int& n, const Rational& ra) {
	Rational tmp((double)n);
	return tmp + ra;
}
Rational operator -(const int& n, const Rational& ra) {
	Rational tmp((double)n);
	return tmp - ra;
}
Rational operator *(const int& n, const Rational& ra) {
	Rational tmp((double)n);
	return tmp * ra;
}
Rational operator /(const int& n, const Rational& ra) {
	Rational tmp((double)n);
	return tmp / ra;
}
Rational Rational::operator +=(const int& n) {
	Rational tmp((double)n);
	*this += tmp;
	return *this;
}
Rational Rational::operator -=(const int& n) {
	Rational tmp((double)n);
	*this -= tmp;
	return *this;
}
Rational Rational::operator *=(const int& n) {
	Rational tmp((double)n);
	*this *= tmp;
	return *this;
}
Rational Rational::operator /=(const int& n) {
	Rational tmp((double)n);
	*this /= tmp;
	return *this;
}
// 重写cout<<Rational输出方法
ostream& operator <<(ostream& os, const Rational& ra)
{
	if (ra.fenzi == 0)
		os << 0;
	else if (ra.negative())
		if (abs(ra.fenmu) == 1)
			os << "-" << abs(ra.fenzi);
		else
			os << "-" << abs(ra.fenzi) << "/" << abs(ra.fenmu); //如果是负数，符号写在前面。
	else
		if (abs(ra.fenmu) == 1)
			os << ra.fenzi;
		else
			os << ra.fenzi << "/" << ra.fenmu;
	return os;
}
// 重写cin>>Rational输入方法
istream& operator >>(istream& is, Rational& ra)
{
	string s;
	is >> s;

	int pos = s.find("/", 0);

	string sTmp = s.substr(0, pos);
	ra.fenzi = atoi(sTmp.c_str());//读入分子
	sTmp = s.substr(pos + 1, s.length() - pos - 1);
	ra.fenmu = atoi(sTmp.c_str());//读入分母

	return is;
}
