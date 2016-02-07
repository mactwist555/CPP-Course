#include <iostream>
#include <string>
using namespace std;

class Student
{
    public:
    void SetName( const string& value )
    {
        name = value;
    }

    void SetClassName( int index, const string& value )
    {
        classNames[index] = value;
    }

    void DisplayInfo()
    {
        cout << "Student: \t" << name << endl << endl;
        cout << "Classes:" << endl;;
        for ( int i = 0; i < 3; i++ )
        {
            cout << "\t\t" << (i+1) << ". " << classNames[i] << endl;
        }
        cout << endl;
    }

    private:
    string name;
    string classNames[3];
};

int main()
{
    Student students[2];

    students[0].SetName( "Havid Dayter" );
    students[0].SetClassName( 0, "Boxes 101" );
    students[0].SetClassName( 1, "Bandanas and You" );
    students[0].SetClassName( 2, "Using remote control missiles for sniping duels" );

    students[1].SetName( "Kideo Hojima" );
    students[1].SetClassName( 0, "Gears of Metal" );
    students[1].SetClassName( 1, "Ender Zones" );
    students[1].SetClassName( 2, "Memorial of Tokimeki" );

    for ( int i = 0; i < 2; i++ )
    {
        cout << endl;
        students[i].DisplayInfo();
    }

    return 0;
}
