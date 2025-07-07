#include "../include/Car.hpp"
#include <string>
#include <iostream>

// code of Car class
Car::Car(std::string name, double speed) : name_(name), speed_(speed) {} //member initialize list


Car::Car(const Car& other) //copy constructor
{

}

Car& Car::operator=(const Car& other) //복사 대입 생성자 (반환 타입 설정 중요)
{

}

Car::~Car() //destructor
{
    std::cout << "\nDelete Car class\n";
}

void Car::ShowData(){
    std::cout << "Saved User Name : " << name_ <<std::endl; 
    std::cout << "Saved User Speed : " << speed_ << std::endl;
}

// end of Car class
