#include <iostream>
#include <vector>
#include "../inc/maxSubarray.hh"
#include "../inc/matrix.hh"

std::vector<std::vector<int>> matrix::_strassenSMatrices = { 
    {0, 1, 1, 1},
    {0,0,0,1},
    {1,0,1,1},
    {1,0,0,0},
    {0,0,1,1},
    {0,0,1,1},
    {0,1,1,1},
    {1,0,1,1},
    {0,0,1,0},
    {0,0,0,1}
};

int main(int argc, char** argv)
{ 
    matrix firstMatrix ( 4, 4);

    matrix resultMatrix(2,2);

    firstMatrix.readArray(argv[1]);

    firstMatrix.print(std::cout);
    std::cout << std::endl;

    firstMatrix.strassenMultiply(firstMatrix, firstMatrix);
    return 0;
}