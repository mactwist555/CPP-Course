#include "Player.h"

void Player::Move()
{
	m_speed = 5;
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) )
	{
		m_position.x -= m_speed;
	}
	else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) )
	{
		m_position.x += m_speed;
	}
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Up ) )
	{
		m_position.y -= m_speed;
	}
	else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Down ) )
	{
		m_position.y += m_speed;
	}
	m_sprite.setPosition( m_position.x, m_position.y );
}

