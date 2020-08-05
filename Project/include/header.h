#pragma once
#include <iostream>
#include <stdexcept>

void foo();

// Math Class
// Include basic operation: + - * /
class CMath
{
public:
    template<typename _type>
    static _type add(_type left, _type right)
    {
        return left + right;
    }

    template<typename _type>
    static _type sub(_type left, _type right)
    {
        return left - right;
    }

    template<typename _type>
    static _type multi(_type left, _type right)
    {
        return left * right;
    }

    template<typename _type>
    static _type div(_type left, _type right)
    {
        if (0 == right)
        {
            throw std::runtime_error("0 can not be divisor!\n");
        }
        return left / right;
    }
};

template<typename _type>
class CDigit
{
public:
    CDigit(_type tvalue = 0);
    CDigit& operator = (const CDigit& right);
    CDigit operator + (const CDigit& right);
    CDigit& operator += (const CDigit& right);
    _type value()
    {
        return m_tvalue;
    }
private:
    _type m_tvalue;
};

template<typename _type>
CDigit<_type>::CDigit(_type tvalue /*= 0*/)
{
    m_tvalue = tvalue;
}

template<typename _type>
CDigit<_type>& CDigit<_type>::operator=(const CDigit& right)
{
    m_tvalue = static_cast<_type>(right.m_tvalue);
}

template<typename _type>
CDigit<_type> CDigit<_type>::operator+(const CDigit& right)
{
    CDigit result(m_tvalue + right.m_tvalue);
    return result;
}

template<typename _type>
CDigit<_type>& CDigit<_type>::operator+=(const CDigit& right)
{
    this->m_tvalue += right.m_tvalue;
    return *this;
}