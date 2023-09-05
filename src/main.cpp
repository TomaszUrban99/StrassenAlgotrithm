#include <iostream>
#include <vector>
#include "../inc/maxSubarray.hh"
#include "../inc/matrix.hh"


int main(int argc, char** argv)
{ 
    matrix firstMatrix ( 3, 3);

    firstMatrix.readArray(argv[1]);

    firstMatrix.print(std::cout);
    
    return 0;
}