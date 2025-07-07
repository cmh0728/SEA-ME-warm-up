#pragma once
#include <memory>
#include <string>
class Unique{
    public:
        Unique(std::string name) ;
        ~Unique();
        void drive();
    private:
        std::string name_;
};