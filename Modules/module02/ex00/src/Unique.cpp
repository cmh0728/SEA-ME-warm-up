#include "../include/Unique.hpp"
#include <iostream>

Unique::Unique(std::string name):name_(name){
    std::cout << name_ << " unique construct\n";
}

Unique::~Unique(){
    std::cout << name_ << " unique destruct\n";
}

void Unique::drive(){
    std::cout << name_ << " unique driving\n";
}