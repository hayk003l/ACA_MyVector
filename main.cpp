#include <iostream>
#include "Vector.hpp"



int main() {
    myStl::Vector<int> vec = {1, 2, 3, 4};
    std::cout << vec[0] << std::endl;
    std::cout << vec[1] << std::endl;
    std::cout << vec[2] << std::endl;
    std::cout << vec[3] << std::endl;
    return 0;
}