#ifndef MATRIX_HH
#define MATRIX_HH

#include <iostream>
#include <fstream>
#include <ostream>

class matrix {

    int _rows;
    int _cols;

    int **_matrixData;

    void readData(std::ifstream &fileHandle);

    public:

    matrix ( int rows, int cols);

    ~matrix();

    void readArray( char *fileName);

    void print ( std::ostream &outputStream);

};

#endif