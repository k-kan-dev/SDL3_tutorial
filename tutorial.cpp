#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

const int WIDTH = 800,  HEIGHT = 600;


int main( int argc, char *argv[] )
{
    bool res = SDL_Init(SDL_INIT_VIDEO); // means SDL_INIT( SDL_INIT_EVERYHTING)

    SDL_Window *window = SDL_CreateWindow(
        "Hello SDL WORLD",
        WIDTH, HEIGHT, 
        SDL_WINDOW_HIGH_PIXEL_DENSITY | SDL_WINDOW_RESIZABLE
    );
    
    if ( NULL == window)
    {
        std::cout << "Could not create window: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer( window, "software");
    SDL_SetRenderDrawColor(renderer, 200, 100, 30, 25);
    // SDL_SetRenderVSync(renderer, -1);

    SDL_RenderClear( renderer );

    SDL_RenderPresent( renderer );

    SDL_Event windowEvent;

    while ( true )
    {
        if ( SDL_PollEvent( &windowEvent ) )
        {
            if ( SDL_EVENT_QUIT == windowEvent.type )
            { break; }

            /**
             * -----------
             * Mouse Event
             * -----------
             * 1.position
             * 2.button
             * 3.wheel
             */
            // position
            if (SDL_EVENT_MOUSE_MOTION == windowEvent.type)
            {
                float x, y;
                SDL_GetMouseState(&x, &y);

                std::cout << x << ":" << y << std::endl;
            }
            // button
            if ( SDL_EVENT_MOUSE_BUTTON_DOWN == windowEvent.type )
            {
                if (SDL_BUTTON_LEFT == windowEvent.button.button )
                { std::cout << "Left Mouse Button was down" << std::endl; }
                if (SDL_BUTTON_RIGHT == windowEvent.button.button )
                { std::cout << "right Mouse Button was down" << std::endl; }
                if (SDL_BUTTON_MIDDLE == windowEvent.button.button )
                { std::cout << "Middle Mouse Button was down" << std::endl; }
                if (SDL_BUTTON_X1 == windowEvent.button.button )
                { std::cout << "x1 Mouse Button was down" << std::endl; }
                if (SDL_BUTTON_X2 == windowEvent.button.button )
                { std::cout << "x2 Mouse Button was down" << std::endl; }
            }
            if ( SDL_EVENT_MOUSE_BUTTON_UP == windowEvent.type )
            {
                if (SDL_BUTTON_LEFT == windowEvent.button.button )
                { std::cout << "Left Mouse Button was up" << std::endl; }
                if (SDL_BUTTON_RIGHT == windowEvent.button.button )
                { std::cout << "right Mouse Button was up" << std::endl; }
                if (SDL_BUTTON_MIDDLE == windowEvent.button.button )
                { std::cout << "Middle Mouse Button was up" << std::endl; }
                if (SDL_BUTTON_X1 == windowEvent.button.button )
                { std::cout << "x1 Mouse Button was up" << std::endl; }
                if (SDL_BUTTON_X2 == windowEvent.button.button )
                { std::cout << "x2 Mouse Button was up" << std::endl; }
            }
            // wheel
            if (SDL_EVENT_MOUSE_WHEEL == windowEvent.type )
            {
                if ( windowEvent.wheel.y > 0 )
                { std::cout << "Mouse Wheel is scrolling up." << std::endl; }
                if ( windowEvent.wheel.y < 0 )
                { std::cout << "Mouse Wheel is scrolling down." << std::endl; }
            }

            /**
             * key down
             */
            if ( SDL_EVENT_KEY_DOWN == windowEvent.type )
            {
                if ( SDLK_ESCAPE == windowEvent.key.key )
                { break; }
                // std::cout << "Key is donw" << std::endl; 
                if ( SDLK_W == windowEvent.key.key )
                { std::cout << "up" << std::endl; }
                if ( SDLK_A == windowEvent.key.key )
                { std::cout << "left" << std::endl; }
                if ( SDLK_S == windowEvent.key.key )
                { std::cout << "down" << std::endl; }
                if ( SDLK_D == windowEvent.key.key )
                { std::cout << "right" << std::endl; }
            }
            else if ( SDL_EVENT_KEY_UP == windowEvent.type )
            { std::cout << "Key is up" << std::endl; }
        }
    }

    SDL_DestroyRenderer( renderer );
    SDL_DestroyWindow( window );
    SDL_Quit( );

    return EXIT_SUCCESS;
}