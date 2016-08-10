//Object.h - Aidan St G

#ifndef OBJECT_H
#define OBJECT_H

#include <SDL.h>
#include <Texture.h>
#include <string>

using std::string;

class Object : public Texture
{
    public:
        Object( SDL_Renderer* ren, int x, int y, int w, int h );
        Object( SDL_Renderer* ren );
        virtual ~Object();

        bool update();
        void setX( int x );
        void setY( int y );
        void setWidth( int w );
        void setHeight( int h );
        void fitToBox( int x, int y, int w, int h );
        void changeText( string new_text );
        string getText();

    private:
        int X = 0;
        int Y = 0;
};

#endif // OBJECT_H
