#include <iostream>
#include "Vector.hpp"



int main() {
    myStl::Vector<int> vec(10);
    vec[0] = 3;
    vec[1] = 43;
    vec[2] = 22;
    vec[3] = -7;
    vec[4] = 11;
    vec[5] = -43;
    vec[6] = 0;
    vec[7] = 4;
    vec[8] = 1;

    std::cout << vec.at(30) << std::endl;

    return 0;
}