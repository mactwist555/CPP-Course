#include <iostream>
#include <string>
using namespace std;

class Animal
{
    public:
    void SetName( const string& name )
    {
        m_name = name;
    }

    void Speak()
    {
        cout << m_name << ": Huh?" << endl;
    }

    protected:
    string m_name;
};

class Cat : public Animal
{
    public:
    void Speak()    // Overwrite Function
    {
        cout << m_name << ": MEOW!" << endl;
    }

    void Claw()     // New functionality
    {
        cout << m_name
            << " destroys all your furniture" << endl;
    }
};



int main()
{
    Animal myAnimal;
    Cat myCat;

    myAnimal.SetName( "Bessie" );
    myCat.SetName( "Fluffy" );

    myAnimal.Speak();
    myCat.Speak();

    myCat.Claw();

    return 0;
}

