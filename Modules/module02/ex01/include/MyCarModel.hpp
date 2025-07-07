#pragma once
#include <string>
#include <vector>

class Part {
public:
    virtual void print() = 0; // Pure virtual function to be overridden by derived classes
    virtual ~Part() = default;
};

class Engine : public Part {
public:
    void print() override ;
    Engine(const std::string& type);

private:
    std::string engine_type_;
};

class Wheel : public Part {
public:
    
    void print() override ;
    Wheel(int f , int r);
    

private : 
    int front_size_;
    int rear_size_;
};

class Brake : public Part {
public:
    void print() override ;
};

class Transmission : public Part {
public:
    void print() override ;
};

class Car {
public:
    Car() ;
    
    void printParts() ;
    
    // ~Car();
    
private:
    //replace to smart pointer
    std::unique_ptr<Engine> engine_;
    std::unique_ptr<Transmission> transmission_;
    std::vector<std::unique_ptr<Wheel>> wheels_;
    std::vector<std::unique_ptr<Brake>> brakes_;
};