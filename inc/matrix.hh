#ifndef MATRIX_HH
#define MATRIX_HH

#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>

class matrix {

    static std::vector<std::vector<int>> _strassenSMatrices;

    int _rows;
    int _cols;

    int **_matrixData;

    void readData(std::istream &fileHandle);

    public:

    matrix ( int rows, int cols);

    ~matrix();

    int getRows () { return _rows; }

    int getCols () { return _cols; }

    int** getMatrixData () { return _matrixData; }

    void readArray( char *fileName);

    void print ( std::ostream &outputStream);

    matrix& substractSubmatrices (   matrix &resultMatrix, std::vector<int> &code );
    
    matrix& addSubmatrices ( matrix &resultMatrix, std::vector<int> &code);

    matrix strassenMultiply ( matrix &matrix_A, matrix &matrix_B);

    matrix squareMatrixMultiply ( matrix &matrix_A, matrix &matrix_B);
};

#endif