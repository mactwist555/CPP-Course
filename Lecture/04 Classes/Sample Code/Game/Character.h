#ifndef _CHARACTER
#define _CHARACTER

#include <SFML/Graphics.hpp>

struct Vector
{
	float x, y;
};

class Character
{
	public:
	void SetTexture( sf::Texture& texture );
	void SetPosition( float x, float y );

	void Move();

	sf::Sprite& GetSprite();

	int GetX();
	int GetY();

	protected:
	Vector m_position;
	sf::Sprite m_sprite;
	float m_speed;
};

#endif
