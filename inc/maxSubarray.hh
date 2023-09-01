#ifndef MAX_SUBARRAY_HH
#define MAX_SUBARRAY_HH

#include <vector>

#include "randomInputData.hh"

class maxSubarray {

    randomInputData _inputData;

    int* _differentialData;

    std::vector<int> _maxSubarray;

    std::vector<int>& maxVector (
        std::vector<int>& lowerVector,
        std::vector<int>& upperVector,
        std::vector<int>& crossVector
    );

    void inputTransform ();

    public:

    randomInputData& getInputData () { return _inputData; }

    maxSubarray( int minValue, int maxValue, int arraySize, char *outputFile) : 
    _inputData(minValue, maxValue, arraySize)
    {
        _inputData.randomArray();
        _inputData.arrayToFile(outputFile);

        _maxSubarray = std::vector<int> {
                0, 
                arraySize-1 , 
                _inputData[arraySize-1] - _inputData[0]
        };
    }

    ~maxSubarray() { delete [] _differentialData; }
    
    std::vector<int> maxArray ();

    std::vector<int> maxCrossingArray ( int minIndex, int maxIndex, int middleIndex);

    std::vector<int> findMaxSubarray ( int minIndex, int maxIndex );

};

#endif