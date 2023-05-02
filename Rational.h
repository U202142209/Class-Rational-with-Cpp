#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

using namespace std;

class Rational
{
private:
    int fenzi, fenmu;
    void simply();//����
    bool negative() const;//�ж��Ƿ��Ǹ���
public:
    Rational(int numerator = 0, int denominator = 1);//���캯��
    Rational(const double n);//����ת�����캯��
    Rational(const Rational& ra);//���ƹ��캯��
    //~Rational();û�ж�̬���䣬Ĭ����������

    Rational& operator =(const Rational& ra);
    Rational& operator =(const double& n);//ʹ������������ܱ�double���͸�ֵ

    //����20������ʹ������������ܺ�double���ͻ�ϼӼ��˳��͸�ֵ
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
    // ������������int�ļ���
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

    //����ǿ������ת���������ʹ�÷���Ӧ�ó���double�͵ĵط������������������������������磬����ʹ��
    //��������������ͨdouble�ͱȽϴ�С��Ϊ����
    operator double();

    //֧����m/n��ʽ��������������������,���Ż���ʾ��ǰ�档
    friend ostream& operator <<(ostream& os, const Rational& ra);
    friend istream& operator >>(istream& is, Rational& ra);
};

#endif
