#include <iostream>
using namespace std;

#include <SDL.h>

#include <cstdlib>

#include "Characters.hpp"

int main( int argc, char* args[] )
{
    int screenWidth = 1920;
    int screenHeight = 1080;
    // Initialize
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        cerr << SDL_GetError() << endl;
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow( "SDL Project",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        screenWidth, screenHeight,
        SDL_WINDOW_SHOWN );

    SDL_Surface* surface = SDL_GetWindowSurface( window );
    SDL_Event event;

    Character player;
    player.LoadImage( "ninja.bmp" );
    player.SetDimensions( 64, 96 );
    player.SetPosition( screenWidth/2, screenHeight/2 );

    NPC enemy[10];

    for ( int i = 0; i < 10; i++ )
    {
        enemy[i].LoadImage( "rabbit.bmp" );
        enemy[i].SetDimensions( 64, 64 );
        enemy[i].SetPosition( rand() % screenWidth, rand() % screenHeight );
    }

    bool done = false;
    while ( !done )
    {
        // Window "X" key pressed
        while( SDL_PollEvent( &event ) != 0 )
        {
            if( event.type == SDL_QUIT ) { done = true; }
        }

        for ( int i = 0; i < 10; i++ )
        {
            enemy[i].SetTarget( player.GetX(), player.GetY() );
            enemy[i].Update();
        }

        // Keypress
        const Uint8* keyStates = SDL_GetKeyboardState( NULL );

        if      ( keyStates[ SDL_SCANCODE_UP ] )    { player.Move( NORTH ); }
        else if ( keyStates[ SDL_SCANCODE_DOWN ] )  { player.Move( SOUTH ); }
        else if ( keyStates[ SDL_SCANCODE_LEFT ] )  { player.Move( WEST ); }
        else if ( keyStates[ SDL_SCANCODE_RIGHT ] ) { player.Move( EAST ); }

        // Draw rectangle
        SDL_Rect fullScreen = { 0, 0, screenWidth, screenHeight };
        SDL_FillRect( surface, &fullScreen, SDL_MapRGB( surface->format,
                0x7B, 0xBF, 0xFF ) ); // r, g, b

        player.Draw( surface );

        for ( int i = 0; i < 10; i++ )
        {
            enemy[i].Draw( surface );
        }

        // Update screen
        SDL_UpdateWindowSurface( window );
    }

    // Close
    SDL_DestroyWindow( window );
    SDL_Quit();
    return 0;
}
