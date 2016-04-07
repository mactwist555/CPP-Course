#include <iostream>
using namespace std;

#include <SDL.h>

#include "Characters.hpp"

int main( int argc, char* args[] )
{
    // Initialize
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        cerr << SDL_GetError() << endl;
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow( "SDL Project",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        640, 480,
        SDL_WINDOW_SHOWN );

    SDL_Surface* surface = SDL_GetWindowSurface( window );
    SDL_Event event;

    bool done = false;
    while ( !done )
    {
        // Window "X" key pressed
        while( SDL_PollEvent( &event ) != 0 )
        {
            if( event.type == SDL_QUIT ) { done = true; }
        }

        // Keypress
        const Uint8* keyStates = SDL_GetKeyboardState( NULL );

        // Draw rectangle
        SDL_Rect fullScreen = { 0, 0, 800, 600 };
        SDL_FillRect( surface, &fullScreen, SDL_MapRGB( surface->format,
                0x7B, 0xBF, 0xFF ) ); // r, g, b

        // Update screen
        SDL_UpdateWindowSurface( window );
    }

    // Close
    SDL_DestroyWindow( window );
    SDL_Quit();
    return 0;
}
