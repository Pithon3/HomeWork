//CreateTaskButton.h - Controls the mechanisms for creating a button - Aidan St. G

#include "CreateTaskButton.h"

CreateTaskButton::CreateTaskButton( SDL_Renderer* ren, int num, int gray ) {
    renderer = ren;
    number = num;

    obj = new Object( renderer );
    obj->loadText( "add task...", { gray, gray, gray }, 18 );
}

CreateTaskButton::~CreateTaskButton() {

}

void CreateTaskButton::update( double factor ) {
    SDL_RenderDrawLine( renderer, ( factor * number ) + 5, 52, ( factor * ( number + 1 ) ) - 5, 52 );
    SDL_RenderDrawLine( renderer, ( factor * number ) + 5, 52, ( factor * number ) + 5, 77 );
    SDL_RenderDrawLine( renderer, ( factor * ( number + 1 ) ) - 5, 52, ( factor * ( number + 1 ) ) - 5, 77 );
    SDL_RenderDrawLine( renderer, ( factor * number ) + 5, 77, ( factor * ( number + 1 ) ) - 5, 77 );

    int w = factor - 16;
    if ( w >= 75 ) {
        obj->changeText( "add task..." );
    } else if ( 75 > w && w > 66 ) {
        obj->changeText( "add tas..." );
    } else if ( 66 >= w && w > 59 ) {
        obj->changeText( "add ta..." );
    } else if ( 59 >= w && w > 51 ) {
        obj->changeText( "add t..." );
    } else if ( 51 >= w && w > 46 ) {
        obj->changeText( "add ..." );
    } else if ( 46 >= w && w > 41 ) {
        obj->changeText( "add..." );
    } else if ( 41 >= w && w > 32 ) {
        obj->changeText( "ad..." );
    } else if ( 32 >= w && w > 23 ) {
        obj->changeText( "a..." );
    } else if ( 23 >= w && w > 15 ) {
        obj->changeText( "..." );
    }

    obj->setX( ( factor * number ) + 8 );
    obj->setY( 55 );
    obj->update();
}
