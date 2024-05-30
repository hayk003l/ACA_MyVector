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
    vec.push_front(1);
    vec.push_front(1);
    vec.push_front(1);
    vec.push_front(1);
    vec.push_front(1);
    vec.push_front(1);
    vec.push_front(1);
    vec.push_front(1);
    vec.push_front(1);
    vec.push_front(1);
    vec.push_front(1);
    vec.push_front(1);
    vec.push_front(1);
    vec.push_front(1);
    vec.push_front(1);
    std::cout << vec.getCap() << std::endl;
    return 0;
}