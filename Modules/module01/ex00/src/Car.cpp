#include "../include/Car.hpp"
#include <string>
#include <iostream>

Car::Car(std::string name, double speed) : name(name), speed(speed) {} //멤버 이니셜라이즈 리스트 형식 


Car::Car(const Car& other) //복사 생성자
{

}

Car& Car::operator=(const Car& other) //복사 대입 생성자 (반환 타입 설정 중요)
{

}

Car::~Car() //소멸자
{
    std::cout << "\nDelete Car class\n";
}

void Car::ShowData(){
    std::cout << "Saved User Name : " << name <<std::endl; 
    std::cout << "Saved User Speed : " << speed << std::endl;
}
