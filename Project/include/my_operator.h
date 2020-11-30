//////////////////////////////////////////////////////////////////////////
/*
The file introduces some basic knowledge about operator overloading
C++ can almost overload all operators except "." ".*" "::" "?:"
Operator can be overloaded as non-static member function or non-member function
*/
//////////////////////////////////////////////////////////////////////////
#pragma once
#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////
/*
Unary operator
Pre-operator
U oprd <=> oprd.operator U()

Post-operator
oprd++ <=> oprd.operator++(0)
*/
//////////////////////////////////////////////////////////////////////////
class Clock
{
public:
    Clock(int hour = 0, int minute = 0, int second = 0)
    {
        if (0 <= hour && hour < 24 && 0 <= minute && minute < 60 && 0 <= second && second < 60)
        {
            this->hour = hour;
            this->minute = minute;
            this->second = second;
        }
        else
        {
            cout << "time error" << endl;
        }
    }

    friend ostream& operator << (ostream& out, const Clock& c);

    // pre
    Clock& operator ++ ()
    {
        if (60 == ++second)
        {
            second = 0;
            if (60 == ++minute)
            {
                minute = 0;
                hour = (hour + 1) % 24;
            }
        }
        return *this;
    }
    // post
    Clock operator ++ (int)
    {
        Clock old(*this);
        ++(*this);
        return old;
    }

private:
    int hour, minute, second;
};

ostream& operator << (ostream& out, const Clock& c)
{
    return out << c.hour << ":" << c.minute << ":" << c.second << endl;
}

//////////////////////////////////////////////////////////////////////////
/*
Binary operator

--------------------------------------------
One: Override operator as member function
num of parameter = num of oprd - 1
oprd1 B oprd2 equals to oprd1.operator B(oprd2)

--------------------------------------------
Two: Override Operator as non-member function
Some operator can not override as member function, such as
1. left operand is not an object for a binary operator
2. the third library or interfaces
Rules:
num of parameter = num of operand (except post ++ or --)
at least one custom parameter
declare override function as friend for a class as it need to access private member
oprd1 B oprd2 equals to operator B(oprd1, oprd2)
*/
//////////////////////////////////////////////////////////////////////////
class Complex
{
public:
    Complex(double r = 0.0, double i = 0.0) : m_real(r), m_imag(i) {}

    // member
    Complex operator + (const Complex& other)
    {
        return Complex(m_real + other.m_real, m_imag + other.m_imag);
    }
    Complex operator - (const Complex& other)
    {
        return Complex(m_real - other.m_real, m_imag - other.m_imag);
    }
    // friend
    friend Complex operator + (const Complex& c1, const Complex& c2);
    friend Complex operator - (const Complex& c1, const Complex& c2);
    friend ostream& operator << (ostream& out, const Complex& c);

private:
    double m_real;
    double m_imag;
};

Complex operator + (const Complex& c1, const Complex& c2)
{
    return Complex(c1.m_real + c2.m_real, c1.m_imag + c2.m_imag);
}

Complex operator - (const Complex& c1, const Complex& c2)
{
    return Complex(c1.m_real - c2.m_real, c1.m_imag - c2.m_imag);
}

// support cout complex as (real, imag)
ostream& operator << (ostream& out, const Complex& c)
{
    return out << "(" << c.m_real << ", " << c.m_imag << ")";
}