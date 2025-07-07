#ifndef CAR_HPP
#define CAR_HPP
#include <string>

class Car{
    private:
        std::string name;
        double speed;
    public : 
        Car(std::string name,double speed); //기본 생성자

        Car(const Car& other); //복사 생성자

        Car& operator=(const Car& other); //복사 대입 생성자 

        ~Car(); //소멸자

        void ShowData();
};

#endif