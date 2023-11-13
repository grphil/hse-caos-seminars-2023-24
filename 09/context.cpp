#include "context.h"

void TContext::SwitchContext() {
    intptr_t* rspp = &rsp;
    intptr_t* ripp = &rip;

    asm volatile (
        "pushq %%rbp\n"
        "\n"
        "movq (%%rcx), %%rax\n"
        "movq %%rsp, (%%rcx)\n"
        "movq %%rax, %%rsp\n"
        "\n"
        "pushq (%%rdx)\n"
        "movq $jump_to_finish, (%%rdx)\n"
        "ret\n"
    "jump_to_finish:\n"
        "popq %%rbp\n"
        : "+c"(rspp), "+d"(ripp)
        :
        : "memory", "rax", "rbx", "rsi", "rdi", "r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15"
    );
}