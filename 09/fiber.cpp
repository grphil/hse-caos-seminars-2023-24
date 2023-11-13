#include "fiber.h"

#include <cstdlib>

constexpr size_t STACK_SIZE = 100'000;

TFiber::TFiber(std::function<void()> f)
    : f(std::move(f))
    , stack(calloc(STACK_SIZE, 1))
{}

TFiber::~TFiber() {
    free(stack);
}

void TFiber::Run() {
    f();
}

intptr_t TFiber::GetStack() {
    return reinterpret_cast<intptr_t>(stack) + STACK_SIZE - sizeof(intptr_t);
}