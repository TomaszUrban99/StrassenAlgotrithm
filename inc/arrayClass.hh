#ifndef ARRAY_CLASS_HH
#define ARRAY_CLASS_HH

#include <iostream>
#include <fstream>
#include <cerrno>
#include <cstring>
#include <exception>

class arrayClass {

    int **_arrayData = NULL;

    /* Attribute for storing dimensions of array */
    int _dimensions;

    int allocateMemory();

    public:

    arrayClass( int arraySize );
    arrayClass () = default;

    ~arrayClass () {

        if ( _arrayData != NULL)
        {
            for ( int i = 0; i < _dimensions; ++i )
                delete [] _arrayData[i]; 
        }

    }

    void readNewArray ( char *filenameData );

    /*!
        \brief Method to check whether given number is power of 2.
    */
    int isPowerTwo ();

    /*!
        \brief Method counting number of rows, which should be added in
        order to use Strassen Algorithm.
    */
    int rowsLeft ();  
};

#endif