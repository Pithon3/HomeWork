//Object.cpp - A basic object to display on the screen - Aidan St G

#include "Object.h"
#include <iostream>
#include <SDL.h>

using std::cout;
using std::string;

Object::Object( SDL_Renderer* ren, int x, int y, int w, int h ) : Texture( ren ) {
    X = x;
    Y = y;
    width = w;
    height = h;
}

Object::Object( SDL_Renderer* ren ) : Texture( ren ) {}

Object::~Object() {

}

bool Object::update() {
    render( X, Y );
}

void Object::setX( int x ) {
    X = x;
}

void Object::setY( int y ) {
    Y = y;
}

void Object::setWidth( int w ) {
    width = w;
}

void Object::setHeight( int h ) {
    height = h;
}

void Object::fitToBox( int x, int y, int w, int h) {
    X = x;
    Y = y;
    width = w;
    height = h;
}

void Object::changeText( string new_text ) {
    loadText( new_text, color, font_size );
}

string Object::getText() {
    return text;
}
