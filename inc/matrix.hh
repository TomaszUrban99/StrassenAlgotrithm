#ifndef MATRIX_HH
#define MATRIX_HH

#include <iostream>
#include <fstream>
#include <ostream>

class matrix {

    int _rows;
    int _cols;

    int **_matrixData;

    void readData(std::istream &fileHandle);

    public:

    matrix ( int rows, int cols);

    ~matrix();

    int** getMatrixData () { return _matrixData; }

    void readArray( char *fileName);

    void print ( std::ostream &outputStream);

    matrix substractSubmatrices (   int firstMatrixRow, int firstMatrixCol,
                                    int secondMatrixRow, int secondMatrixCol );

    matrix strassenMultiply ( matrix &matrix_A, matrix &matrix_B);

};

#endif