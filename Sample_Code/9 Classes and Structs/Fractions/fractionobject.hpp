#ifndef _FRACTION
#define _FRACTION

    class Fraction
    {
        private:
        int numerator, denominator;

        public:
        // Don't forget to call setup
        // immediately after creation!!
        void Setup( int n, int d )
        {
            numerator = n;
            denominator = d;
        }
    }

    void GetUserInput()
    {
        cout << "Enter a numerator & denominator: ";
        cin >> numerator >> denominator;
    }

    void Display()
    {
        cout << numerator << "/" << denominator;
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
};

#endif
