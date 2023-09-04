#include "../inc/arrayClass.hh"
#include <boost/move/detail/type_traits.hpp>
#include <fstream>
#include <scoped_allocator>

arrayClass::arrayClass ( int arraySize )
{
    try 
    {
        if ( arraySize < 1 ) throw std::exception();
    }
    catch ( const std::exception &e)
    {
        std::cerr << "Incorrect size of new array" << std::endl;
        exit(1);
    }

    _dimensions = arraySize;

    allocateMemory();

}

int arrayClass::allocateMemory()
{
    _fullDimension = _dimensions + rowsLeft();

    /* Allocate memory block of size _dimensions */
    _arrayData = new int*[_fullDimension];

    std::cout << "Full dimension: " << _fullDimension << std::endl;
    std::cout << "Rows left: " << rowsLeft() << std::endl;

    for ( int i = 0; i < _fullDimension; ++i)
    {
        _arrayData[i] = new int[_fullDimension];
        
        if (_arrayData[i] == NULL )
            return -1;
    }

    return 0;
}

int arrayClass::rowsLeft()
{
    int rows = 1;

    while ( rows < _dimensions )
        rows = rows * 2;

    return rows - _dimensions;
}

int arrayClass::isPowerTwo ()
{
    int rows = _dimensions;
    
    while ( rows > 1)
    {
        rows = rows % 2;
    }

    return rows;
}

void arrayClass::readNewArray(char *filenameData )
{
    std::ifstream fileHandle ( filenameData );

    /* Check whether the file has been opened correctly */
    try {
        if (fileHandle.fail())
            throw 3;
    }
    catch ( int exception){
        std::cerr << "Failed to open the file" << std::endl;
        exit(3);
    }

    /* 
        Format of input file:
            size_of_input_array
            number number number ..... EOF
    */

    fileHandle >> _dimensions;

    /* Allocate memory for read _dimensions of an array */
    if(_arrayData == NULL)
    {
        allocateMemory();
    }

    while (!fileHandle.eof())
    {
        for ( int i = 0; i < _fullDimension; ++i )
        {
            for ( int j = 0; j < _fullDimension; ++j )
            {
                if ( j >=  _dimensions || i >= _dimensions)
                    _arrayData[i][j] = 0;
                else {
                    fileHandle >> _arrayData[i][j];
                }
                
            }
        }
    }
}

void arrayClass::print()
{
    for ( int i = 0; i < _fullDimension; ++i )
    {
        for ( int j = 0; j < _fullDimension; ++j )
            {
                std::cout << _arrayData[i][j] << " ";
            }
        std::cout << std::endl;
    }
}

arrayClass arrayClass::add_subarray(    int beginFirst, int endFirst,
                                        int beginSecond, int endSecond )
{

}