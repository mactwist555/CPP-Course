#include <iostream>
#include <string>
using namespace std;

class Canine
{
    public:
    Canine( const string& name )
    {
        cout << "Canine Constructor" << endl;
        m_name = name;
    }

    virtual ~Canine()
    {
        cout << "Canine Destructor" << endl;
    }

    protected:
    string m_name;
};

class Corgi : public Canine
{
    public:
    Corgi( const string& name ) : Canine( name )
    {
        cout << "Corgi Constructor" << endl;
    }

    virtual ~Corgi()
    {
        cout << "Corgi Destructor" << endl;
    }
};

int main()
{
    Canine* corgi = new Corgi( "Ein" );
    delete corgi;

    return 0;
}


