#ifndef METRIC_HPP
#define METRIC_HPP

#include <iostream>
#include <string>
using namespace std;

class Metric
{
    public:
    Metric() { }
    Metric( float val ) { Set( val ); }
    virtual string GetUnit() = 0;
    virtual string GetSquaredUnit() = 0;
    float Get() const       { return m_value; }
    void Set( float val )   { m_value = val; }
    void Output() { cout << m_value << " " << GetUnit() << endl; }

    protected:
    float m_value;
};

class Feet : public Metric
{
    public:
    Feet() { }
    Feet( float val ) : Metric( val ) { }
    virtual string GetUnit() { return "ft"; }
    virtual string GetSquaredUnit() { return "sqft"; }
};

class Meter : public Metric
{
    public:
    Meter() { }
    Meter( float val ) : Metric( val ) { }
    virtual string GetUnit() { return "m"; }
    virtual string GetSquaredUnit() { return "m^2"; }
};

#endif
