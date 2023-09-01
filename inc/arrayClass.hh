#ifndef ARRAY_CLASS_HH
#define ARRAY_CLASS_HH

#include <iostream>
#include <fstream>

#include <boost/interprocess/file_mapping.hpp>
#include <boost/interprocess/mapped_region.hpp>

class arrayClass {

    int **_arrayData;

    /* Attributes for storing dimensions of array */
    int _rowNumber;

    int _colNumber;

    public:

    arrayClass( int arraySize );

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