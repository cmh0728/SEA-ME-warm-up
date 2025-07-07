#pragma once

#include <memory>
#include <string>

class Weak{
    public:
        Weak(std::string name);
        ~Weak();

    private:
        std::string name_;

};