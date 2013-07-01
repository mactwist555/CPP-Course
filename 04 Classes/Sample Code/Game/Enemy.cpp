#include "Enemy.h"

void Enemy::Move( Player player )
{
	m_speed = 2;
	if ( player.GetX() < m_position.x )
	{
		m_position.x -= m_speed;
	}
	else
	{
		m_position.x += m_speed;
	}

	if ( player.GetY() < m_position.y )
	{
		m_position.y -= m_speed;
	}
	else
	{
		m_position.y += m_speed;
	}
	m_sprite.setPosition( m_position.x, m_position.y );
}
