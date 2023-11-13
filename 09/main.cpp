#include <iostream>

#include "scheduler.h"

int main() {
    AddFunc([]() {
        std::cout << 1 << '\n';
        Yield();
        std::cout << 3 << '\n';
    });

    AddFunc([]() {
        std::cout << 2 << '\n';
        Yield();
        std::cout << 4 << '\n';
    });

    RunFuncs();
}
