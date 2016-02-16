#include <string>
#include <iostream>
using namespace std;

class Parent
{
    public:
    void SetName( const string& name ) { m_name = name; }
    string GetName() { return m_name; }

    protected:
    string m_name;
};

class Child : public Parent
{
    public:
    void SetName( const string& name )
    {
        m_name = "";
        for ( int i = name.size() - 1; i >= 0; i-- )
        {
            m_name += name[i];
        }
    }
};

int main()
{
    // Normal variables

    Parent p;
    Child c;

    p.SetName( "George" );
    c.SetName( "George" );

    cout << "Parent: " << p.GetName() << ", Child: " << c.GetName() << endl;

    // Pointers

    Parent* ptrObject = &p;
    ptrObject->SetName( "Object" );
    cout << "Pointer A: " << ptrObject->GetName() << endl;
    cout << "and...:    " << p.GetName() << endl;

    ptrObject = &c;
    ptrObject->SetName( "Object" );
    cout << "Pointer B: " << ptrObject->GetName() << endl;
    cout << "and...:    " << c.GetName() << endl;

    c.SetName( "Name2" );
    cout << "Pointer B: " << ptrObject->GetName() << endl;
    cout << "and...:    " << c.GetName() << endl;

    // Dynamic variables

    Parent* p1 = new Parent;
    Parent* p2 = new Child;

    p1->SetName( "Jim" );
    p2->SetName( "Jim" );

    cout << "Dynamic 1: " << p1->GetName() << endl;
    cout << "Dynamic 2: " << p2->GetName() << endl;

    delete p1;
    delete p2;

    return 0;
}


