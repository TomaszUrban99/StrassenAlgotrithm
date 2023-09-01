#ifndef RANDOM_INPUT_DATA_HH
#define RANDOM_INPUT_DATA_HH

#include <iostream>
#include <fstream>

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

class randomInputData 
{
    /* Array with random input data */
    int *_outputArray;
    
    int _minimumValue;
    int _maximumValue;

    int _valueNumber;

    boost::random::mt19937 _numberGenerator;

    int randomNumber ();

  
    public:

    randomInputData( int minimumValue, int maximumValue, int valueNumber)
    {
        _minimumValue = minimumValue;
        _maximumValue = maximumValue;
        _valueNumber = valueNumber;

        _outputArray = new int[_valueNumber];
    }

    ~randomInputData()
    {
        delete [] _outputArray;
    }

    int getValueNumber () { return _valueNumber;}
    
    void randomArray ();

    void arrayToFile ( char *filename );

    int operator[] ( int arrayIndex );
};

#endif