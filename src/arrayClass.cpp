#include "../inc/arrayClass.hh"
#include <boost/interprocess/detail/os_file_functions.hpp>
#include <boost/interprocess/file_mapping.hpp>
#include <boost/interprocess/mapped_region.hpp>

arrayClass::arrayClass ( int arraySize )
{
    if ( arraySize < 1 )
    {

    }

    _rowNumber = arraySize;
}

int arrayClass::rowsLeft()
{
    int rows = 1;

    while ( rows < _rowNumber )
        rows = rows * 2;

    return rows - _rowNumber;
}

int arrayClass::isPowerTwo ()
{
    int rows = _rowNumber;
    
    while ( rows > 1)
    {
        rows = rows % 2;
    }

    return rows;
}

void arrayClass::readNewArray(char *filenameData )
{
    /* Use mapping technique for reading files */
    const boost::interprocess::mode_t fileMode = boost::interprocess::read_only;
    boost::interprocess::file_mapping fileHandle ( filenameData, fileMode);
    
    boost::interprocess::mapped_region fileRegion(fileHandle,fileMode,0,0);
    
    const char* fileBegin = static_cast<const char*>(fileRegion.get_address());
}