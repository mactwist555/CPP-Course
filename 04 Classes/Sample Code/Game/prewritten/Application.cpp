#include "Application.h"

#include <iostream>

Application::Application()
{
	m_window.create(sf::VideoMode( 800, 600 ), "CS 201");


    if ( !m_txPlayer.loadFromFile( "dog.png" ) )
    {
    	std::cout << "Error loading dog.png" << std::endl;
    }

    if ( !m_txEnemy.loadFromFile( "rabbit.png" ) )
    {
    	std::cout << "Error loading rabbit.png" << std::endl;
    }
}

bool Application::IsRunning()
{
	sf::Event event;
	while ( m_window.pollEvent( event ) )
	{
		if ( event.type == sf::Event::Closed )
			m_window.close();
	}
	return true;
}

void Application::BeginDrawing()
{
	m_window.clear( sf::Color( 0, 100, 0 ) );
}

void Application::DrawSprite( sf::Sprite& sprite )
{
	m_window.draw( sprite );
}

void Application::EndDrawing()
{
	m_window.display();
}
