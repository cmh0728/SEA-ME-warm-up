#include "../include/Car.hpp"
#include <iostream>
#include <string>

int main()
{
    std::string user_name ;
    double user_speed;
    std::cout << "Input user name : ";
    std::cin >> user_name;
    std::cout << "Input user speed : ";
    std::cin >> user_speed;

    Car c(user_name , user_speed) ;
    
    c.ShowData();

    return 0;
}