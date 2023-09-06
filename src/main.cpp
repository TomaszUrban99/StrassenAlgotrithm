#include <iostream>
#include <vector>
#include "../inc/maxSubarray.hh"
#include "../inc/matrix.hh"


int main(int argc, char** argv)
{ 
    matrix firstMatrix ( 4, 4);
    matrix secondMatrix ( 4, 4);

    firstMatrix.readArray(argv[1]);
    secondMatrix.readArray(argv[2]);

    firstMatrix.print(std::cout);
    std::cout << std::endl;
    secondMatrix.print(std::cout);
    std::cout << std::endl;

   firstMatrix.substractSubmatrices(0, 1, 1, 1).print(std::cout);

    
    return 0;
}