#include <iostream>
#include <vector>
#include "../inc/maxSubarray.hh"
#include "../inc/arrayClass.hh"

int main(int argc, char** argv)
{ 
    int a1 = 5;
    int a2 = 8;

    arrayClass firstMatrix (a1);
    arrayClass secondMatrix (a2);

    std::cout << firstMatrix.isPowerTwo() << std::endl;
    std::cout << secondMatrix.isPowerTwo() << std::endl;

    firstMatrix.readNewArray(argv[1]);

    std::cout << "Rows left: " << firstMatrix.rowsLeft() << std::endl;
    std::cout << "Rows left, second matrix: " << secondMatrix.rowsLeft() << std::endl;

    firstMatrix.print();

    arrayClass thirdMatrix(-2);

    return 0;
}