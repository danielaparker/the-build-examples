#include <iostream>
#include <example.hpp>

int main()
{
    double* leak = new double[10];
    std::cout << "Hello!" << std::endl;
}
