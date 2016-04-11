#include "Characters.hpp"

Character::Character()
{
    m_speed = 5;
}

Character::~Character()
{
    SDL_FreeSurface( m_image );
}

void Character::LoadImage( const string& path )
{
    m_image = SDL_LoadBMP( path.c_str() );
}

void Character::SetPosition( float x, float y )
{
    m_x = x;
    m_y = y;
}

void Character::SetDimensions( int width, int height )
{
    m_width = width;
    m_height = height;
}

void Character::Move( Direction dir )
{
    if ( dir == NORTH )
    {
        m_y -= m_speed;
    }
    else if ( dir == SOUTH )
    {
        m_y += m_speed;
    }
    else if ( dir == WEST )
    {
        m_x -= m_speed;
    }
    else if ( dir == EAST )
    {
        m_x += m_speed;
    }
}

void Character::Draw( SDL_Surface* screen )
{
    SDL_Rect pos;
    pos.x = m_x;
    pos.y = m_y;
    pos.w = m_width;
    pos.h = m_height;

    SDL_BlitSurface( m_image, NULL, screen, &pos );
}

float Character::GetX()
{
    return m_x;
}

float Character::GetY()
{
    return m_y;
}

NPC::NPC()
{
    m_goalX = 0;
    m_goalY = 0;
    m_speed = 1;
}

void NPC::SetTarget( float x, float y )
{
    m_goalX = x;
    m_goalY = y;
}

void NPC::Update()
{
    if ( m_goalX < m_x )
    {
        Move( WEST );
    }
    else if ( m_goalX > m_x )
    {
        Move( EAST );
    }

    if ( m_goalY < m_y )
    {
        Move( NORTH );
    }
    else if ( m_goalY > m_y )
    {
        Move( SOUTH );
    }
}









