//Array.cpp - An array for Objects - Aidan St G

//THE CONTENT OF THIS FILE WAS COMBINED WITH THAT OF ARRAY.H, THIS FILE IS NO LONGER NEEDED.

/*#include <iostream>
#include "Array.h"
#include "Object.h"

using std::cout;

template<class T> Array<T>::Array( T* objs[], int l ) {
    objects = objs;
    length = l;
}

template<class T> Array<T>::~Array() {
    for ( int i = 0; i < length; i++ ) {
        delete objects[i];
        objects[i] = NULL;
    }
    objects = NULL;
    length = 0;
}

template<class T> void Array<T>::check() {
    for ( int i = 0; i < length; i++ ) {
        cout << objects[ i ] << " - ";
    }
}

template<class T> bool Array<T>::add( T* obj ) {
    int i = getEmptySpot();
    if ( i == -1 ) {
        return false;
    }

    objects[ i ] = obj;
    length++;

    return true;
}

template<class T> T* Array<T>::get( int i ) {
    return objects[i];
}

template<class T> int Array<T>::getSize() {
    return length;
}

template<class T> int Array<T>::getEmptySpot() {
    for ( int i = 0; i < length; i++) {
        if ( objects[ i ] == NULL ) {
            return i;
        }
    }
    return -1;
}*/
