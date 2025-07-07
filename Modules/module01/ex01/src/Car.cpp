#include "../include/Car.hpp"
#include <string>
#include <iostream>

//인스턴스 생성할때, 값을 입력받고 저장 
Car::Car(const std::string& make, const std::string& model, int year)
    : make(make), model(model), year(year) {
    std::cout << "[Car constructor]" << std::endl;
}



Car::~Car() //소멸자
{
    std::cout << "\n[Car destructor]]\n";
}

void Car::drive() const{

    std::cout << "\n[Car::drive()]!!\n";

    std::cout << "\nCar's make : " << make ; 
    std::cout << "\nCar's model : " << model ;
    std::cout << "\nCar's year : " << year ;

}
