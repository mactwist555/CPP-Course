#ifndef _FELINE
#define _FELINE

class Feline
{
    public:
    Feline( const string& name );

    virtual void Purr() = 0;
    virtual void Meow() = 0;

    void Name( const string& name );
    string Name();

    protected:
    string m_name;
};

Feline::Feline( const string& name )
{
    Name( name );
}

void Feline::Name( const string& name )
{
    m_name = name;
}

string Feline::Name()
{
    return m_name;
}




class HouseCat : public Feline
{
    public:
    HouseCat( const string& name ) : Feline( name ) { }

    virtual void Purr();
    virtual void Meow();
};

void HouseCat::Purr()
{
    cout << m_name << " the house cat: Purr!" << endl;
}

void HouseCat::Meow()
{
    cout << m_name << " the house cat: Meow!" << endl;
}



class Lion : public Feline
{
    public:
    Lion( const string& name ) : Feline( name ) { }

    virtual void Purr();
    virtual void Meow();
};

void Lion::Purr()
{
    cout << m_name << " the lion: Purr!" << endl;
}

void Lion::Meow()
{
    cout << m_name << " the lion: Meow!" << endl;
}


#endif
