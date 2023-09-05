#include "../inc/matrix.hh"
#include <fstream>
#include <ostream>
#include <pthread.h>

void matrix::readData(std::ifstream &fileHandle)
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