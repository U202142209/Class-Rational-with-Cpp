#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

using namespace std;

class Rational
{
private:
    int fenzi, fenmu;
    void simply();//化简
    bool negative() const;//判断是否是负数
public:
    Rational(int numerator = 0, int denominator = 1);//构造函数
    Rational(const double n);//类型转换构造函数
    Rational(const Rational& ra);//复制构造函数
    //~Rational();没有动态分配，默认析构就行

    Rational& operator =(const Rational& ra);
    Rational& operator =(const double& n);//使有理数类对象能被double类型赋值

    //以下20个函数使有理数类对象能和double类型混合加减乘除和赋值
    Rational operator +(const Rational& ra);
    Rational operator -(const Rational& ra);
    Rational operator *(const Rational& ra);
    Rational operator /(const Rational& ra);
    friend Rational operator +(const double& n, const Rational& ra);
    friend Rational operator -(const double& n, const Rational& ra);
    friend Rational operator *(const double& n, const Rational& ra);
    friend Rational operator /(const double& n, const Rational& ra);
    Rational& operator +=(const Rational& ra);
    Rational& operator -=(const Rational& ra);
    Rational& operator *=(const Rational& ra);
    Rational& operator /=(const Rational& ra);

    Rational operator +(const double& n);
    Rational operator -(const double& n);
    Rational operator *(const double& n);
    Rational operator /(const double& n);
    Rational& operator +=(const double& n);
    Rational& operator -=(const double& n);
    Rational& operator *=(const double& n);
    Rational& operator /=(const double& n);
    // 有理数与整数int的计算
    Rational operator +(const int& n);
    Rational operator -(const int& n);
    Rational operator *(const int& n);
    Rational operator /(const int& n);
    friend Rational operator +(const int& n, const Rational& ra);
    friend Rational operator -(const int& n, const Rational& ra);
    friend Rational operator *(const int& n, const Rational& ra);
    friend Rational operator /(const int& n, const Rational& ra);
    Rational operator +=(const int& n);
    Rational operator -=(const int& n);
    Rational operator *=(const int& n);
    Rational operator /=(const int& n);

    int GetFenzi() { return fenzi; }
    int GetFenmu() { return fenmu; }
    void Set(int numerator, int denominator) { fenzi = numerator; fenmu = denominator; }

    //重载强制类型转换运算符，使得凡是应该出现double型的地方，均可以由有理数类对象替代。比如，可以使得
    //有理数类对象和普通double型比较大小成为可能
    operator double();

    //支持以m/n形式的有理数类对象输入输出,负号会显示在前面。
    friend ostream& operator <<(ostream& os, const Rational& ra);
    friend istream& operator >>(istream& is, Rational& ra);
};

#endif
