#include <iostream>
#include <thread>
#include <chrono>

/*
멀티쓰레딩 -->  여러 동작이 병렬로 처리됨(동시에 실행)
*/ 

void task1() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Task 1: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // 느리게
    }
}

void task2() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Task 2: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // 느리게
    }
}

void task3() {
    for (int i = 0; i < 5; ++i) {
        std::cout << "Task 3: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // 느리게
    }
}


int main() {
    std::thread t1(task1);
    std::thread t2(task2);
    std::thread t3(task3);

    t1.join();
    t2.join();
    t3.join();

    std::cout << "Main thread done." << std::endl;
    return 0;
}
