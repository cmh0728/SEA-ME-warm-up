#pragma once
#include <memory>
#include <string>
class Shared{
    public:
        Shared(std::string name) ;
        ~Shared();
        void drive();
    private:
        std::string name_;
};

void sharedCar(std::shared_ptr<Shared> sc);