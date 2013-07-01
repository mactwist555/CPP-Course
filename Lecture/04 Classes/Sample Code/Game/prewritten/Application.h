#ifndef _APP
#define _APP

#include <SFML/Graphics.hpp>

class Application
{
	public:
	Application();

	bool IsRunning();

	void BeginDrawing();
	void DrawSprite( sf::Sprite& sprite );
	void EndDrawing();

	sf::Texture& GetPlayerTexture() { return m_txPlayer; }
	sf::Texture& GetEnemyTexture() { return m_txEnemy; }

	private:
	sf::RenderWindow m_window;
    sf::Texture m_txPlayer, m_txEnemy;
};

#endif
