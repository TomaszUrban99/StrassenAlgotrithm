#include "../inc/matrix.hh"
#include <fstream>
#include <ostream>
#include <pthread.h>

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

matrix matrix::substractSubmatrices(    int firstMatrixRow, int firstMatrixCol,
                                        int secondMatrixRow, int secondMatrixCol )
{
    int split = _rows/2;

    /* Create new matrix */
    matrix newMatrix ( _rows/2, _cols/2 );

    int startPointFirstRow = firstMatrixRow * split;
    int startPointFirstCol = firstMatrixCol * split;

    int startPointSecondRow = secondMatrixRow * split;
    int startPointSecondCol = secondMatrixCol * split; 

    for ( int i = 0; i < split; ++i ){
        for ( int j = 0; j < split; ++j ){
            
            (newMatrix.getMatrixData())[i][j] = 
                _matrixData[startPointFirstRow+i][startPointFirstCol+j] 
                - _matrixData[startPointSecondRow + i][startPointSecondCol + j];
        }
    }

    return newMatrix;
}

matrix matrix::strassenMultiply( matrix& matrix_A, matrix& matrix_B)
{

}