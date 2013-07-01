#include "Character.h"

void Character::SetTexture( sf::Texture& texture )
{
	m_sprite.setTexture( texture );
}

void Character::SetPosition( float x, float y )
{
	m_position.x = x;
	m_position.y = y;
	m_sprite.setPosition( x, y );
}

sf::Sprite& Character::GetSprite()
{
	return m_sprite;
}

int Character::GetX()
{
	return m_position.x;
}

int Character::GetY()
{
	return m_position.y;
}
