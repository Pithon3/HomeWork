//Display.h - Header for Display - Aidan St G

#include <Array.h>
#include <Calendar.h>
#include <Texture.h>
#include <Object.h>
#include <CreateTaskButton.h>
#include <SDL.h>
#include <string>

#ifndef DISPLAY_H
#define DISPLAY_H

using std::string;

class Display
{
    public:
        Display( SDL_Window* win, SDL_Renderer* ren, Calendar* cal );
        bool mainloop();
        virtual ~Display();

    protected:

    private:
        int screenWidth;
        int screenHeight;
        double factor;
        const int gray = 100;

        Array<Object>* dayWords = NULL;
        Array<Object>* dateWords = NULL;
        Array<CreateTaskButton>* createTaskButtons = NULL;
        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;
        Calendar* calendar;

        bool renderText( string text, SDL_Color color, int font_size, Array<Object>* arr );
};

#endif // DISPLAY_H

//75 66 59 51 46 41 32 23 15
