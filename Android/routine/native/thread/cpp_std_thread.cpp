#include <thread>
#include <iostream>
#include <chrono>
#include <string>


void delay_s(int time)
{
    std::this_thread::sleep_for(std::chrono::seconds(time));
}


void first_func()
{
    for (int i = 0; i < 10; i++) {
        std::cout << "==Thread A == " << i << std::endl;
        delay_s(1);
    }
    std::cout << "end of thread A" << std::endl;
}

void sec_func(int cst)
{
    for (int i = 0; i < 10; i++) {
        std::cout << "==Thread B == " << i << " " << cst << std::endl;
        delay_s(1);
    }
    std::cout << "end of thread B" << std::endl;
}


int main()
{
    std::cout << "main thread invoke f/s thread" << std::endl;
    std::thread first(first_func);
    std::thread second(sec_func, 77);

    std::cout << "main thread join f/s thread" << std::endl;
    first.join();
    second.join();

    std::cout << "end of main thread thread" << std::endl;

    return 0;
}