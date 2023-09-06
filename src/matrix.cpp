#include "../inc/matrix.hh"
#include <fstream>
#include <ostream>
#include <pthread.h>
#include <vector>

void matrix::readData(std::istream &fileHandle)
{
    for ( int i = 0; i < _rows; ++i )
    {
        for ( int j = 0; j < _cols; ++j )
            fileHandle >> _matrixData[i][j];
    }

    try {
        if ( fileHandle.fail())
            throw false;
    }
    catch ( bool isFailed )
    {
        std::cerr << "Failed to read matrix" << std::endl;
        exit(3);
    }
}

matrix::matrix( int rows, int cols )
{
    _rows = rows;
    _cols = cols;

    /* Memory allocation */
    
    _matrixData = new int*[rows];
    
    for (int i = 0; i < _rows; ++i ){
        _matrixData[i] = new int[_cols];
    }
}

matrix::~matrix()
{
    for ( int i = 0; i < _rows; ++i)
    {
        delete [] _matrixData[i];
    }

    delete [] _matrixData;
}

void matrix::readArray(char *fileName)
{
    std::ifstream fileHandle (fileName);

    /* Check whether file could be opened directly */
    try
    {
        if(fileHandle.fail())
            throw false;   
    }
    catch( bool isFailed)
    {
        std::cerr << "Unable to open file: " << fileName << std::endl;
        exit (1);
    }

    fileHandle >> _rows;
    fileHandle >> _cols;

    try
    {
        if (fileHandle.fail())
            throw false;
    }
    catch ( bool isFailed)
    {
        std::cerr << "Unable to read matrix dimensions" << std::endl;
        exit (2);
    }

    /* Read integers to matrix */
    readData(fileHandle);   

}

void matrix::print(std::ostream &outputStream)
{
    try 
    {
        if (outputStream.fail())
            throw false;
    }
    catch ( bool isFailed )
    {
        std::cerr << "Incorrect file handle" << std::endl;
        exit(4); 
    }

    for ( int i = 0; i < _rows; ++i )
    {
        for ( int j = 0; j <_cols; ++j )
            outputStream << _matrixData[i][j] << " ";

        outputStream << std::endl;
    }
}

matrix& matrix::substractSubmatrices(    matrix& resultMatrix, std::vector<int> &code )
{
    int split = resultMatrix.getRows();

    int startPointFirstRow = code[0] * split;
    int startPointFirstCol = code[1] * split;

    int startPointSecondRow = code[2] * split;
    int startPointSecondCol = code[3] * split; 

    for ( int i = 0; i < split; ++i ){
        for ( int j = 0; j < split; ++j ){
            
            (resultMatrix.getMatrixData())[i][j] = 
                _matrixData[startPointFirstRow+i][startPointFirstCol+j] 
                - _matrixData[startPointSecondRow + i][startPointSecondCol + j];
        }
    }

    return resultMatrix;
}

matrix& matrix::addSubmatrices(  matrix& resultMatrix, std::vector<int> &code )
{
    int split = resultMatrix.getRows();

    int startPointFirstRow = code[0] * split;
    int startPointFirstCol = code[1] * split;

    int startPointSecondRow = code[2] * split;
    int startPointSecondCol = code[3] * split; 

    for ( int i = 0; i < split; ++i ){
        for ( int j = 0; j < split; ++j ){
            
            (resultMatrix.getMatrixData())[i][j] = 
                _matrixData[startPointFirstRow+i][startPointFirstCol+j] 
                + _matrixData[startPointSecondRow + i][startPointSecondCol + j];
        }
    }

    return resultMatrix;
}

matrix matrix::strassenMultiply( matrix& matrix_A, matrix& matrix_B)
{
    matrix temporary (1,1);

    int split = matrix_A.getRows()/2;
    
    std::vector<matrix*> matricesVector (10);
    
    /* Create instance of S matrices */

    for ( int i = 0; i < 10; ++i ){
        matricesVector[i] = new matrix(split, split);
    }

    /* S1 matrix */
    matrix_B.substractSubmatrices(*matricesVector[0], _strassenSMatrices[0]);
    /* S2 matrix */
    matrix_A.addSubmatrices(*matricesVector[1], _strassenSMatrices[1]);
    /* S3 matrix */
    matrix_A.addSubmatrices(*matricesVector[2], _strassenSMatrices[2]);
    /* S4 matrix */
    matrix_B.substractSubmatrices(*matricesVector[3], _strassenSMatrices[3]);
    /* S5 matrix */
    matrix_A.addSubmatrices(*matricesVector[4], _strassenSMatrices[4]);
    /* S6 matrix */
    matrix_B.addSubmatrices(*matricesVector[5], _strassenSMatrices[5]);
    /* S7 matrix */
    matrix_A.substractSubmatrices(*matricesVector[6], _strassenSMatrices[6]);
    /* S8 matrix */
    matrix_B.addSubmatrices(*matricesVector[7], _strassenSMatrices[7]);
    /* S9 matrix */
    matrix_A.substractSubmatrices(*matricesVector[8], _strassenSMatrices[8]);
    /* S10 matrix */
    matrix_B.addSubmatrices(*matricesVector[9], _strassenSMatrices[9]);

    std::cout << "Results: " << std::endl;

    for ( int i = 0; i < 10; ++i ){
        std::cout << "S macierz " << i << std::endl;
        matricesVector[i]->print(std::cout);
        std::cout << std::endl;
    }
    
    for ( int i = 0; i < 10; ++i ){
        delete matricesVector[i];
    }

    return temporary;
}

matrix matrix::squareMatrixMultiply( matrix& matrix_A, matrix& matrix_B)
{
    
}