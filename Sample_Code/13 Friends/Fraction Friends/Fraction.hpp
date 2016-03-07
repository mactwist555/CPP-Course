#ifndef _FRACTION
#define _FRACTION

class Fraction
{
    public:
    void Setup( int num, int denom );
    void Display();

    friend Fraction Multiply( const Fraction& one, const Fraction& two );

    private:
    int m_num, m_denom;
};

#endif
