#ifndef CHARACTERS_HPP
#define CHARACTERS_HPP

#include <SDL.h>

#include <string>
using namespace std;

enum Direction { NORTH, SOUTH, EAST, WEST };

class Character
{
    public:
    Character();
    ~Character();

    void LoadImage( const string& path );
    void SetPosition( float x, float y );
    void SetDimensions( int width, int height );
    void Move( Direction dir );
    void Draw( SDL_Surface* screen );

    float GetX();
    float GetY();

    protected:
    SDL_Surface* m_image;
    int m_width, m_height;
    float m_speed;
    float m_x, m_y;
};

class NPC : public Character
{
    public:
    NPC();

    void SetTarget( float x, float y );
    void Update();

    private:
    float m_goalX, m_goalY;
};

#endif
