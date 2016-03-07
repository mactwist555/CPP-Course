#include "Fraction.hpp"

#include <iostream>
using namespace std;

void Fraction::Setup( int num, int denom )
{
    m_num = num;
    m_denom = denom;
}

void Fraction::Display()
{
    cout << m_num << "/" << m_denom;
}
