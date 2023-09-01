#include "../inc/randomInputData.hh"
#include <cstring>
#include <fstream>
#include <ostream>
#include <stdexcept>

int randomInputData::randomNumber()
{
    boost::random::uniform_int_distribution<> distr(_minimumValue, _maximumValue);
    return distr(_numberGenerator);
}

void randomInputData::randomArray()
{
    for ( int i = 0; i < _valueNumber; ++i )
    {
        _outputArray[i] = randomNumber();
    }
}

int randomInputData::operator[] (int arrayIndex )
{
    return _outputArray[arrayIndex];
}

void randomInputData::arrayToFile ( char *filename )
{
    std::ofstream outputFile ( filename );
    
    if (outputFile.fail())
        {
            throw std::runtime_error(strerror(errno));
        }
    
    for ( int i = 0; i < _valueNumber; ++i )
    {
        outputFile << _outputArray[i] << " ";
    }
}
