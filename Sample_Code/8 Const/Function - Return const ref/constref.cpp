#include <iostream>
#include <string>
using namespace std;

struct Data
{
    string info;
    int id;
};

class DataContainer
{
    public:
    DataContainer()
    {
        for ( int i = 0; i < 20; i++ )
        {
            data[i].id = (i+1)*10;
            data[i].info = char( i + 65 );
        }
    }

    const Data& GetItem( int index )
    {
        return data[index];
    }

    private:
    Data data[20];
};

int main()
{
    DataContainer dc;
    cout << dc.GetItem( 0 ).id << ", " << dc.GetItem( 0 ).info << endl;
    cout << dc.GetItem( 2 ).id << ", " << dc.GetItem( 2 ).info << endl;
    cout << dc.GetItem( 4 ).id << ", " << dc.GetItem( 4 ).info << endl;

    //dc.GetItem( 4 ).id = 50; // invalid

    return 0;
}
