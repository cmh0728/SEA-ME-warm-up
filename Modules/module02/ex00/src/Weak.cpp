#include "../include/Weak.hpp"
#include <iostream>

Weak::Weak(std::string name):name_(name){
    std::cout << "Weak construct\n";
}

Weak::~Weak(){
    std::cout << "Weak destruct\n";
}