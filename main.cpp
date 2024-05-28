#include <iostream>
#include "Vector.hpp"



int main() {
    myStl::Vector<int> vec(10);
    vec.push_back(5);
    vec.push_back(5);
    vec.push_back(5);
    vec.push_back(5);
    vec.push_back(5);
    vec.push_back(5);
    vec.push_back(5);
    vec.push_back(5);
    vec.push_back(5);
    vec.push_back(5);
    std::cout << vec[0] << std::endl;
    std::cout << vec[15] << std::endl;
}