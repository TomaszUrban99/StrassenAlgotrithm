#include "../inc/maxSubarray.hh"
#include <vector>

std::vector<int>& maxSubarray::maxVector (
    std::vector<int>& lowerVector,
    std::vector<int>& upperVector,
    std::vector<int>& crossVector
)
{
    if ( lowerVector[2] >= upperVector[2])
    {
        if ( lowerVector[2] >= crossVector[2])
            return lowerVector;
        else
            return crossVector;
    }
    else {
        if (upperVector[2] > crossVector[2]) {
            return upperVector;
        }
        else {
            return crossVector;
        }
    }
}

void maxSubarray::inputTransform ()
{
    int size = _inputData.getValueNumber()-1;
    
    _differentialData = new int[size];

    for ( int i = 0; i < size; ++i )
      _differentialData[i] = _inputData[i+1] - _inputData[i];
}

std::vector<int> maxSubarray::maxArray ()
{
    inputTransform();

    return findMaxSubarray(0, _inputData.getValueNumber()-2);
}

std::vector<int> maxSubarray::maxCrossingArray( int minIndex, int maxIndex, int middleIndex)
{
    /* Vector with coordinates and sum of max crossing array */
    std::vector<int> coordinatesAndSum(3);

    int leftSum = -1000;
    int sum = 0;
    int maxLeft;
    
    for ( int i = middleIndex; i >= minIndex; --i )
    {  
        sum = sum + _differentialData[i];

        if ( sum > leftSum ){
                leftSum = sum;
                maxLeft = i;
        }
    }
    
    int rightSum = -1000;
    sum = 0;
    int maxRight;

    for ( int i = middleIndex + 1; i <= maxIndex; ++i )
    {
        sum = sum + _differentialData[i];
        
        if ( sum > rightSum )
        {
            rightSum = sum;
            maxRight = i;
        }
    }

    coordinatesAndSum[0] = maxLeft;
    coordinatesAndSum[1] = maxRight;
    coordinatesAndSum[2] = rightSum + leftSum;

    return coordinatesAndSum;
}

std::vector<int> maxSubarray::findMaxSubarray ( int minIndex, int maxIndex )
{
    std::vector<int> newVector = { minIndex, maxIndex, _differentialData[minIndex] };

    if ( minIndex == maxIndex)
        return newVector; 
    else
    {
        int midIndex = ( maxIndex + minIndex )/2;
        
        std::vector<int> lowerVector = findMaxSubarray(minIndex, midIndex);
        std::vector<int> upperVector = findMaxSubarray(midIndex+1, maxIndex);
        std::vector<int> crossVector = maxCrossingArray(minIndex, maxIndex, midIndex);

        newVector = maxVector(lowerVector, upperVector, crossVector);
    }

    return newVector;
}