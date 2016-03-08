#ifndef _CALORIES
#define _CALORIES

#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class CalorieItem
{
    public:
    CalorieItem();
    CalorieItem( const string& name, int calories );
    void Setup( const string& name, int calories );
    void SetName( const string& name );
    void SetCalories( int calories );
    void Display();

    friend istream& operator>>( istream& in, CalorieItem& item );
    friend ostream& operator<<( ostream& out, CalorieItem& item );
    CalorieItem& operator=( const CalorieItem& rhs );
    CalorieItem& operator[]( const int index );
    CalorieItem& operator += (const CalorieItem &obj);

    private:
    string m_name;
    int m_calories;
    vector<CalorieItem> m_contents;
};

CalorieItem::CalorieItem()
{
    m_name = "";
    m_calories = 0;
}

CalorieItem::CalorieItem( const string& name, int calories )
{
    m_calories = 0;
    Setup( name, calories );
}

void CalorieItem::Setup( const string& name, int calories )
{
    SetName( name );
    SetCalories( calories );
}

void CalorieItem::SetName( const string& name )
{
    m_name = name;
}

void CalorieItem::SetCalories( int calories )
{
    m_calories = calories;
}

void CalorieItem::Display()
{
    cout << endl << m_name
        << "\t Calories: " << m_calories;

    if ( m_contents.size() > 0 )
    {
        cout << endl << "Ingredients: " << endl;
        for ( int i = 0; i < m_contents.size(); i++ )
        {
            cout << "*" << m_contents[i] << endl;
        }
    }
}

CalorieItem& CalorieItem::operator += (const CalorieItem &obj)
{
    m_contents.push_back( obj );
    m_calories += obj.m_calories;
}

CalorieItem& CalorieItem::operator=( const CalorieItem& rhs )
{
    if ( this == &rhs ) return *this;

    m_name = rhs.m_name;
    m_calories = rhs.m_calories;
    m_contents = rhs.m_contents;

    return *this;
}

CalorieItem& CalorieItem::operator[]( const int index )
{
    return m_contents[index];
}

istream& operator>>( istream& in, CalorieItem& item )
{
    CalorieItem newItem;
    in >> newItem.m_name;
    in >> newItem.m_calories;
    item.m_contents.push_back( newItem );
    item.m_calories += newItem.m_calories;
    return in;
}

ostream& operator<<( ostream& out, CalorieItem& item )
{
    out << setw( 25 ) << item.m_name << setw( 20 )
        << "calories: " << item.m_calories;
    return out;
}

#endif
