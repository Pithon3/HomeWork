//CreateTaskButton.h - Aidan St. G

#include <Object.h>

#ifndef CREATETASKBUTTON_H
#define CREATETASKBUTTON_H

class CreateTaskButton
{
    public:
        CreateTaskButton( SDL_Renderer* ren, int num, int gray );
        virtual ~CreateTaskButton();
        void update( double factor );

    private:
        Object* obj;
        SDL_Renderer* renderer;
        int number;

};

#endif // CREATETASKBUTTON_H
