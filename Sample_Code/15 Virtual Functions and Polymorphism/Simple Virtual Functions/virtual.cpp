#include <iostream>
using namespace std;

class Bear
{
    public:
    virtual void Roar()
    {
        cout << "Bear roar" << endl;
    }

    void EatFish()
    {
        cout << "Bear eats fish" << endl;
    }
};

class Panda : public Bear
{
    public:
    virtual void Roar()
    {
        cout << "Panda roar" << endl;
    }

    void EatFish()
    {
        cout << "Panda eats fish" << endl;
    }
};

int main()
{
    Bear bear1;
    Panda panda1;

    Bear* ptrBear = &bear1;
    Bear* ptrPanda = &panda1;

    Bear* dynamicBear1 = new Bear();
    Bear* dynamicBear2 = new Panda();
    Panda* dynamicPanda = new Panda();

    cout << "ROAR:" << endl;
    dynamicBear1->Roar();          // Calls Bear::Roar
    dynamicBear2->Roar();          // Calls Panda::Roar
    dynamicPanda->Roar();          // Calls Panda::Roar

    ptrBear->Roar();               // Calls Bear::Roar
    ptrPanda->Roar();              // Calls Panda::Roar

    cout << endl << "EAT FISH:" << endl;
    dynamicBear1->EatFish();       // Calls Bear::EatFish
    dynamicBear2->EatFish();       // Calls Bear::EatFish
    dynamicPanda->EatFish();       // Calls Panda::EatFish

    ptrBear->EatFish();            // Calls Bear::EatFish
    ptrPanda->EatFish();           // Calls Bear::EatFish

    delete dynamicBear1;
    delete dynamicBear2;
    delete dynamicPanda;

    return 0;
}
