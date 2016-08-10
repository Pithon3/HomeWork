//Texture.cpp - A class for a texture to display - Aidan St G

#include "Texture.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>

using std::cout;

Texture::Texture( SDL_Renderer* ren ) {
    renderer = ren;

    texture = NULL;
    width = 0;
    height = 0;
}

Texture::~Texture() {
    free();
}

bool Texture::load(string path) {
    free();

    SDL_Texture* new_texture = NULL;
    SDL_Surface* loaded_surface = IMG_Load( path.c_str() );

    if ( loaded_surface == NULL ) {
        cout << "Texture could not load from file!\n";
        return false;
    }

    SDL_SetColorKey( loaded_surface, SDL_TRUE, SDL_MapRGB( loaded_surface->format, 0, 0xFF, 0xFF ) );

    new_texture = SDL_CreateTextureFromSurface( renderer, loaded_surface );

    width = loaded_surface->w;
    height = loaded_surface->h;
    SDL_FreeSurface( loaded_surface );

    texture = new_texture;

    return texture != NULL;
}

bool Texture::loadText( string t, SDL_Color c, int f_size ) {
    free();

    text = t;
    color = c;
    font_size = f_size;

    font = TTF_OpenFont( "\font.ttf", font_size );

    if ( font == NULL ) {
        cout << "Could not load font file!\n";
        return false;
    }

    SDL_Surface* text_surface = TTF_RenderText_Solid( font, text.c_str(), color );

    if ( text_surface == NULL ) {
        cout << "Could not load surface from text!\n";
        return false;
    }

    texture = SDL_CreateTextureFromSurface( renderer, text_surface );

    width = text_surface->w;
    height = text_surface->h;
    SDL_FreeSurface( text_surface );

    return texture != NULL;
}

void Texture::free() {
    if ( texture != NULL ) {
        SDL_DestroyTexture( texture );
        texture = NULL;
        width = 0;
        height = 0;
    }
}

void Texture::render( int x, int y, SDL_Point* center, SDL_Rect* clip, double angle, SDL_RendererFlip flip ) {

	SDL_Rect renderQuad = { x, y, width, height };

	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	SDL_RenderCopyEx( renderer, texture, clip, &renderQuad, angle, center, flip );
}

int Texture::getHeight() {
    return height;
}

int Texture::getWidth() {
    return width;
}
