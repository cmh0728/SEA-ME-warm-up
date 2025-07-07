#ifndef SPORTS_CAR_HPP
#define SPORTS_CAR_HPP

#include "../include/Car.hpp"
#include <string>

class SportsCar : public Car{ //상속
    private :
        double max_speed ;
    public : 
        SportsCar(const std::string& make, const std::string& model , int year , double max_speed);
        ~SportsCar();
        SportsCar(const SportsCar& other);
        void drive() const override;  // 오버라이딩
};


#endif