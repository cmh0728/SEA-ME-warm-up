#include "SportsCar.hpp"
#include <iostream>
#include <string>


int main() {

    std::string make , model;
    int year;
    double max_speed;
    
    std::cout << "\nInput Car's make : " ; 
    std::cin >> make;
    std::cout << "\nInput Car's model : " ;
    std::cin >> model;
    std::cout << "\nInput Car's year : "  ;
    std::cin >> year;
    std::cout << "\nInput Car's max speed : " ;
    std::cin >> max_speed;

    SportsCar sc(make,model,year,max_speed);
    sc.drive();

    SportsCar sc2 = sc;
    sc2.drive();
    return 0;
}
