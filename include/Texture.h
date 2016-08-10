//Texture.h - Header for Texture - Aidan St G

#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL_ttf.h>
#include <SDL.h>
#include <string>

using std::string;

class Texture
{
    public:
        Texture( SDL_Renderer* ren );
        virtual ~Texture();

        bool load( string path );
        bool loadText( string text, SDL_Color color = { 0, 0, 0}, int font_size = 18 );
        void free();
        void setColor( Uint8 r, Uint8 g, Uint8 b );
        void setBlendMode( SDL_BlendMode blendmode );
        void setAlpha( Uint8 a );
        void render( int x, int y, SDL_Point* center = NULL, SDL_Rect* clip = NULL, double angle = 0.0, SDL_RendererFlip flip = SDL_FLIP_NONE );
        int getHeight();
        int getWidth();

        int width;
        int height;
        SDL_Color color;
        int font_size;
        string text;

    private:

        TTF_Font* font = NULL;
        SDL_Texture* texture;
        SDL_Renderer* renderer = NULL;

};

#endif // TEXTURE_H
