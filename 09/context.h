#pragma once

#include <cstdint>

struct TContext {
    intptr_t rsp; // Stack register
    intptr_t rip; // Instruction pointer

    void SwitchContext();
};