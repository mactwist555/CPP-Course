#include <iostream>
#include <string>
using namespace std;

class Fraction
{
    public:
    void Setup( int num, int denom )
    {
        numerator = num;
        denominator = denom;
    }

    void Display()
    {
        cout << "(" << numerator << "/" << denominator << ")";
    }

    void GetUserInput()
    {
        cout << "Enter a numerator & denominator: ";
        cin >> numerator >> denominator;
        Display();
        cout << endl;
    }

    int GetNumerator()
    {
        return numerator;
    }

    int GetDenominator()
    {
        return denominator;
    }

    void SetNumerator( int value )
    {
        numerator = value;
    }

    void SetDenominator( int value )
    {
        denominator = value;
    }

    private:
    int numerator, denominator;
};

Fraction Multiply( Fraction& one, Fraction& two )
{
    Fraction product;
    product.SetNumerator( one.GetNumerator() * two.GetNumerator() );
    product.SetDenominator( one.GetDenominator() * two.GetDenominator() );
    return product;
}

int main()
{
    Fraction a, b, product;

    cout << "Fraction 1" << endl;
    a.GetUserInput();

    cout << "Fraction 2" << endl;
    b.GetUserInput();

    product = Multiply( a, b );

    cout << endl;
    a.Display();
    cout << " x ";
    b.Display();
    cout << " = ";
    product.Display();

    return 0;
}


