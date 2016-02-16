#ifndef _VEHICLE
#define _VEHICLE

#include <string>
using namespace std;

class Vehicle
{
    public:
    Vehicle() : m_position( 0 ), m_velocity( 0 ), m_acceleration( 0 ) { }
    float GetPosition() { return m_position; }
    float GetVelocity() { return m_velocity; }
    float GetAcceleration() { return m_acceleration; }
    string GetName() { return m_name; }

    void Move()
    {
        m_position += m_velocity;
        m_velocity += m_acceleration;
    }

    void Display()
    {
        cout << m_name;

        // Tab over 10 spaces, adjust for length of name.
        for ( int i = 0; i < 10 - m_name.size(); i++ )
        {
            cout << " ";
        }

        cout << ": Position: " << m_position
            << ", Velocity: " << m_velocity
            << ", Acceleration: " << m_acceleration << endl;
    }

    protected:
    float m_position;
    float m_velocity;
    float m_acceleration;
    string m_name;
};

class Bicycle : public Vehicle
{
    public:
    Bicycle() : Vehicle()
    {
        m_acceleration = 1;
        m_name = "Bicycle";
    }
};

class Horse : public Vehicle
{
    public:
    Horse() : Vehicle()
    {
        m_acceleration = 5;
        m_name = "Horse";
    }
};

class Car : public Vehicle
{
    public:
    Car() : Vehicle()
    {
        m_acceleration = 10;
        m_name = "Car";
    }
};

#endif
