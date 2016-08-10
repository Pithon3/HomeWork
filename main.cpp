//main.cpp - The main class from The Home Work Project (THWP) - Aidan St G

#include "SDL.h"
#include "SDL_ttf.h"
#include <Calendar.h>
#include <Display.h>

#include <iostream>

using std::cout;

bool init ();
bool close ();

Display* dis = NULL;
Calendar* cal = NULL;

bool init () {

    SDL_Init( SDL_INIT_VIDEO );
    TTF_Init();

    SDL_Window* win = SDL_CreateWindow( "The HomeWork Project (THWP)", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 360, SDL_WINDOW_RESIZABLE );
    SDL_Renderer* ren = SDL_CreateRenderer( win, -1, SDL_RENDERER_ACCELERATED );


    cal = new Calendar();
    dis = new Display( win, ren, cal );

    return true;
}

bool close () {
    delete cal;
    cal = NULL;

    delete dis;
    dis = NULL;

    SDL_Quit();

    return true;
}

int main( int argc, char* args[] )
{
    init();

    Uint8 color = 0x00;


    SDL_Event e;
    bool quit = false;
    while ( !quit ) {
        while ( SDL_PollEvent( &e ) != 0 ){
            if ( e.type == SDL_QUIT ) {
                quit = true;
            }
        }

        if ( !dis->mainloop() ) {
            quit = true;
        }
    }

    cal = NULL;

    close();

    /*Calendar* cal = new Calendar();

    for ( int a = 1; a <= 12; a++ ) {
        for ( int b = 1; b <= 31; b++ ) {
            cout << '"' << cal->months[a] << ' ' << b << '"' << ", ";
        }
    }*/

    return 0;
}


