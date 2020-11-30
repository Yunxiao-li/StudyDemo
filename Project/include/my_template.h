//////////////////////////////////////////////////////////////////////////
/*
The file introduces some basic knowledge about template
template can reduce repetitive code and avoid consistency issues
*/
//////////////////////////////////////////////////////////////////////////
#pragma once

#include <iostream>
#include <stdexcept>
#include <typeinfo>
#include <cstring>
#include <cassert>

using namespace std;

// template for normal function
// declare and implementation should be placed at .h file
// or else there will be a linked error
template<class T>
void foo()
{
    std::cout << "this is foo, type: " << typeid(T).name() << std::endl;
}

// template for static member function
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

// template for class
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
    if (this != &right)
    {
        m_tvalue = static_cast<_type>(right.m_tvalue);
    }
    return *this;
}

template<typename _type>
CDigit<_type> CDigit<_type>::operator+(const CDigit& right)
{
    return CDigit(m_tvalue + right.m_tvalue);
}

template<typename _type>
CDigit<_type>& CDigit<_type>::operator+=(const CDigit& right)
{
    this->m_tvalue += right.m_tvalue;
    return *this;
}

// template for dynamic array
template<class T>
class DynamicArray
{
public:
    DynamicArray(int size = 50);
    ~DynamicArray();
    DynamicArray(const DynamicArray<T>& other);
    DynamicArray<T>& operator = (const DynamicArray<T>& rhs);
    T& operator [] (int i);
    const T& operator [] (int i) const;
    operator T* ();
    operator const T* () const;
    int size() const;
    void resize(int sz);
private:
    T* m_list;
    int m_size;
};

template<class T>
DynamicArray<T>::DynamicArray(int size /*= 50*/)
{
    assert(size >= 0);
    m_size = size;
    m_list = new T[size];
}

template<class T>
DynamicArray<T>::~DynamicArray()
{
    m_size = 0;
    delete [] m_list;
}

template<class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other)
{
    m_size = other.m_size;
    m_list = new T[m_size];
    memcpy(m_list, other.m_list, m_size);
}

template<class T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& rhs)
{
    if (this != &rhs)
    {
        if (m_size != rhs.m_size)
        {
            delete [] m_list;
            m_size = rhs.m_size;
            m_list = new T[m_size];
        }
        memcpy(m_list, rhs.m_list, m_size);
    }
    return *this;
}

template<class T>
T& DynamicArray<T>::operator[](int i)
{
    assert(i >=0 && i < m_size);
    return m_list[i];
}

template<class T>
const T& DynamicArray<T>::operator[](int i) const
{
    assert(i >=0 && i < m_size);
    return m_list[i];
}

template<class T>
DynamicArray<T>::operator T*()
{
    return m_list;
}

template<class T>
DynamicArray<T>::operator const T*() const
{
    return m_list;
}

template<class T>
int DynamicArray<T>::size() const
{
    return m_size;
}

template<class T>
void DynamicArray<T>::resize(int sz)
{
    assert(sz >= 0);
    if (m_size == sz)
    {
        return;
    }
	T* newList = new T[sz];
	int ismall = sz < m_size ? sz : m_size;
	for (int i = 0; i < ismall; ++i)
	{
		newList[i] = m_list[i];
	}
    delete [] m_list;
    m_list = newList;
	m_size = sz;
}
