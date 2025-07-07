#include "../include/MyCarModel.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <memory>

//class : Engine
void Engine::print(){
    std::cout << "Engine part\n";
    std::cout << "Engine is : " << engine_type_ <<std::endl ;
}

Engine::Engine(const std::string& type) : engine_type_(type){

}


//class : Wheel
Wheel::Wheel(int f, int r):front_size_(f),rear_size_(r){}

void Wheel::print(){
    std::cout << "Wheel part\n";
    std::cout << "front wheel size : " << front_size_ << std::endl;
    std::cout << "rear wheel size : " << rear_size_ << std::endl;
}

//class : Brake
void Brake::print(){
    std::cout << "Brake part\n";
}

//class : Transmission
void Transmission::print(){
    std::cout << "Transmission part\n";
}

//class : Car
Car::Car(){
    engine_ = std::make_unique<Engine>("V12");
    transmission_ = std::make_unique<Transmission>();


    for (int i = 0; i < 4; ++i) {
            wheels_.push_back(std::make_unique<Wheel>(20, 21));  // 인치 예시
            brakes_.push_back(std::make_unique<Brake>());
    }

}

// Car::~Car(){
//         delete engine_;
//         delete [] wheels_;
//         delete [] brakes_;
//         delete transmission_;
//     }

// call print function
void Car::printParts(){
        engine_->print();
        for (const auto& w : wheels_) w->print();
        for (const auto& b : brakes_) b->print();
        transmission_->print();
}