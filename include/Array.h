//Array.h - Aidan St G

#ifndef ARRAY_H
#define ARRAY_H

#include <Object.h>
#include <iostream>

using std::cout;

template<class T> class Array
{
    public:
        Array( int l ) : length(l) {
            objects = new T*[l];
        }

        virtual ~Array() {
            for ( int i = 0; i < length; i++ ) {
                delete objects[i];
                objects[i] = NULL;
            }
            objects = NULL;
            length = 0;
        }

        int getSize() { return length; }

        bool add( T* obj ) {
            int i = getEmptySpot();
            if ( i == -1 ) {
                return false;
            }

            objects[ i ] = obj;
            length++;

            return true;
        }

        T* get( int i ) { return objects[i]; }

        void check() {
            for ( int i = 0; i < length; i++ ) {
                cout << objects[ i ] << " - ";
            }
            cout << "END\n";
        }

    private:
        T** objects;
        int length;

        int getEmptySpot() {
            for ( int i = 0; i < length; i++) {
                if ( objects[ i ] == NULL ) {
                    return i;
                }
            }
            return -1;
        }
};

#endif // ARRAY_H
