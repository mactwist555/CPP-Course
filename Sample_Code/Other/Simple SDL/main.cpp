#include <SDL_image.h>
#include <unistd.h>
#include <iostream>
using namespace std;


int main()
{
    SDL_Window* window;
    SDL_Renderer* renderer;

    // Init
    if ( SDL_Init( SDL_INIT_VIDEO ) != 0 )
    {
        cout << "Error" << endl;
    }

    if ( SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) == false )
    {
        cout << "Error" << endl;
    }

    SDL_Delay( 1000 );

    window = SDL_CreateWindow( "Test Window",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        800, 600, SDL_WINDOW_SHOWN );

    if ( window == NULL )
    {
        cout << "Error creating window" << endl;
    }

    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );

    if ( renderer == NULL )
    {
        cout << "Error creating renderer" << endl;
    }

    if ( ( IMG_Init( IMG_INIT_PNG ) & IMG_INIT_PNG ) == false )
    {
        cout << "Error initializing SDL_Image" << endl;
    }

    // Draw
    SDL_SetRenderDrawColor( renderer, 0x33, 0x33, 0x33, 0xFF );
    SDL_RenderClear( renderer );
    SDL_UpdateWindowSurface( window );
    SDL_Delay( 2000 );


    // Destroy
    SDL_DestroyRenderer( renderer );
    renderer = NULL;
    SDL_DestroyWindow( window );
    window = NULL;
    SDL_Quit();

    return 0;
}
