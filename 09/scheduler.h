#pragma once

#include "context.h"
#include "fiber.h"

#include <queue>
#include <memory>

class TScheduler {
public:
    TScheduler() = default;

    void AddFunc(std::function<void()> f);
    void Run();
private:
    TContext MainContext;
    std::unique_ptr<TFiber> CurrentFiber;

    struct TFiberHolder {
        TFiberHolder(std::unique_ptr<TFiber> fiber, TContext context)
            : fiber(std::move(fiber))
            , context(context)
        {}

        std::unique_ptr<TFiber> fiber;
        TContext context;
    };

    static void StartFiber();

    std::queue<TFiberHolder> Fibers;
    bool FiberFinished = false;

    friend void Yield();
};

void Yield();

void AddFunc(std::function<void()> f);

void RunFuncs();