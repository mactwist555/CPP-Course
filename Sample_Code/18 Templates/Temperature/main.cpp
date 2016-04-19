#include <iostream>
#include <string>
using namespace std;

class Temp
{
    public:
    float value;
    virtual string GetSuffix() const = 0;
};

class Farenheit : public Temp
{
    public:
    virtual string GetSuffix() const { return " F"; }
};

class Celsius : public Temp
{
    public:
    virtual string GetSuffix() const { return " C"; }
};

template <typename T>
void DisplayTemp( const T& temp )
{
    cout << temp.value << temp.GetSuffix() << endl;
}

int main()
{
    Farenheit fTemp;
    fTemp.value = 63;

    Celsius cTemp;
    cTemp.value = 17;

    DisplayTemp( fTemp );
    DisplayTemp( cTemp );

    return 0;
}
