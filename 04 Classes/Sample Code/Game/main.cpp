#include <SFML/Graphics.hpp>

#include "prewritten/Application.h"
#include "Enemy.h"
#include "Player.h"

int main()
{
	Application app;

	Enemy enemy;
	Player player;

	player.SetTexture( app.GetPlayerTexture() );
	enemy.SetTexture( app.GetEnemyTexture() );

	player.SetPosition( 400, 300 );
	enemy.SetPosition( 0, 0 );

	// Start the game loop
    while ( app.IsRunning() )
    {
		player.Move();
		enemy.Move( player );

		// Draw to screen
		app.BeginDrawing();
		app.DrawSprite( player.GetSprite() );
		app.DrawSprite( enemy.GetSprite() );
		app.EndDrawing();

    } // End main game loop

    return 0;
}
