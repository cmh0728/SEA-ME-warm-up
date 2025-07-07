#include "../include/SportsCar.hpp"
#include <iostream>


SportsCar::SportsCar(const std::string& make, const std::string& model , int year , double max_speed) 
    : Car(make,model,year),max_speed(max_speed) {
    std::cout << "[SportsCar constructor]" << std::endl;

} // 

SportsCar::~SportsCar(){
    std::cout << "[SportsCar destructor]" << std::endl;
}


void SportsCar::drive() const {
    Car::drive();  // 부모 클래스의 drive 먼저 실행
    std::cout << "\n[SportsCar::drive()] \n\nTop speed is " << max_speed << " km/h\n" << std::endl;
}

SportsCar::SportsCar(const SportsCar& other): Car(other.make, other.model, other.year),  // 부모 복사 처리
      max_speed(other.max_speed){
    std::cout << "[SportsCar copy constructor]" << std::endl;   
}