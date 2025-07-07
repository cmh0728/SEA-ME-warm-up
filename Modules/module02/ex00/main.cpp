#include "include/Car.hpp"
#include "include/Unique.hpp"
#include "include/Shared.hpp"
#include "include/Weak.hpp"
#include <iostream>
#include <string>
#include <memory>

int main()
{
    std::unique_ptr<Unique> unique = std::make_unique<Unique>("unique_car");
    unique->drive();
    // 함수끝나면 자동으로 delete--> 소멸자 호출

    std::shared_ptr<Shared> shared = std::make_shared<Shared>("shared_car");
    sharedCar(shared);
    shared -> drive(); //마지막 reference이후 사용자 없을 때 소멸자 호출. 


    return 0;
}