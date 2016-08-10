//Display.cpp - Class where the rendering gets done - Aidan St G

#include "Display.h"
#include "Calendar.h"
#include <Array.h>
#include <SDL_ttf.h>
#include <iostream>

using std::cout;

Display::Display( SDL_Window* win, SDL_Renderer* ren, Calendar* cal ) {
    window = win;
    renderer = ren;
    calendar = cal;

    //Object** day_words = new Object*[7];
    dayWords = new Array<Object>( 7 );

    //Object** date_words = new Object*[7];
    dateWords = new Array<Object>( 7 );

    //CreateTaskButton**

    SDL_GetWindowSize( window, &screenWidth, &screenHeight );
    factor = screenWidth / 7;

    int today = calendar->getWeekDay();

    for ( int i = 1; i <= 7; i++ ) {
        int a = 255;
        int b = 255;
        if ( i == today ) {
            a = 0;
            b = 0;
        }
        renderText( calendar->daysoftheweek[ i ], { 255, a, b }, 18, dayWords );
        renderText( calendar->getDate( i - today ), { 255, a, b }, 18, dateWords );
    }

}

bool Display::mainloop() {
    SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0xFF );
    SDL_RenderClear( renderer );

    SDL_GetWindowSize( window, &screenWidth, &screenHeight );
    factor = screenWidth / 7.0 ;

    //DRAW DAYS
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    for ( int i = 1; i < 7; i++ ) {
        SDL_RenderDrawLine( renderer, i * factor, 0, i * factor, screenHeight );
    }
    SDL_RenderDrawLine( renderer, 0, 47, screenWidth, 47);

    for ( int i = 0; i < 7; i++ ) {
        Object* obj1 = dayWords->get(i);
        if ( obj1 != NULL ) {
            obj1->fitToBox( ( i * factor ) + 3, 3, factor - 6, 24 );
            obj1->update();
        }

        Object* obj2 = dateWords->get( i );
        if ( obj2 != NULL ) {
            obj2->fitToBox( ( i * factor ) + 3, 24, factor - 6, 20 );
            obj2->update();
        }

    }

    //DRAW ASSINGMENTS
    SDL_SetRenderDrawColor( renderer, gray, gray, gray, 0xFF );

    for ( int i = 0; i < 7; i++ ) {

    }

    //dayWords->check();

    SDL_RenderPresent( renderer );
    return true;
}

bool Display::renderText( string text, SDL_Color color, int font_size, Array<Object>* arr ) {
    Object* obj = new Object( renderer );
    arr->add(obj);
    obj->loadText( text, color, font_size );
    cout << obj;
}

Display::~Display() {
    SDL_DestroyRenderer( renderer );
	renderer = NULL;

    SDL_DestroyWindow( window );
    window = NULL;
}
