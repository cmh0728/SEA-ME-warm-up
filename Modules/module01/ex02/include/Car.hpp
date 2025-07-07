#ifndef CAR_HPP
#define CAR_HPP
#include <string>

class Car{
    protected: // 자식 클래스에서 접근 가능 
        std::string make;
        std::string model;
        int year;
    public : 
        Car(const std::string& make, const std::string& model , int year); //기본 생성자


        virtual ~Car(); //소멸자

        virtual void drive() const; //가상함수 선언


};

#endif