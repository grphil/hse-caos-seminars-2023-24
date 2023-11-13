#pragma once

#include <functional>
#include <cstdint>

class TFiber {
public:
    TFiber(std::function<void()> f);

    ~TFiber();

    void Run();

    intptr_t GetStack();
private:
    std::function<void()> f;
    void* stack;
};