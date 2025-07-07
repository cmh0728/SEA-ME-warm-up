#include "../include/Shared.hpp"
#include <iostream>

Shared::Shared(std::string name):name_(name){
    std::cout << name_ << " shared construct\n";
}

Shared::~Shared(){
    std::cout << name_ << " shared destruct\n";
}

void Shared::drive(){
    std::cout << name_ << " shared driving\n";
}


void sharedCar(std::shared_ptr<Shared> sc){
    std::cout << "driving in sharedCar function\n";
    sc -> drive();

}