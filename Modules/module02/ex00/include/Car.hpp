#pragma once
#include <string>

//define Car class
class Car{
    private:
        std::string name_;
        double speed_;
    public : 
        Car(std::string name,double speed); 

        Car(const Car& other);

        Car& operator=(const Car& other); 

        ~Car();

        void ShowData(); 
};
