#include "scheduler.h"

namespace {
    TScheduler Scheduler;
}

void TScheduler::AddFunc(std::function<void()> f) {
    auto fiber = std::make_unique<TFiber>(std::move(f));
    TContext context;
    context.rsp = fiber->GetStack();
    context.rip = reinterpret_cast<intptr_t>(&StartFiber);
    Fibers.emplace(std::move(fiber), context);
}

void TScheduler::Run() {
    while (!Fibers.empty()) {
        CurrentFiber = std::move(Fibers.front().fiber);
        MainContext = Fibers.front().context;
        Fibers.pop();

        FiberFinished = false;
        MainContext.SwitchContext();

        if (!FiberFinished) {
            Fibers.emplace(std::move(CurrentFiber), MainContext);
        }
    }
}

void TScheduler::StartFiber() {
    Scheduler.CurrentFiber->Run();
    Scheduler.FiberFinished = true;
    Scheduler.MainContext.SwitchContext();
    __builtin_unreachable();
}

void Yield() {
    Scheduler.MainContext.SwitchContext();
}

void AddFunc(std::function<void()> f) {
    Scheduler.AddFunc(std::move(f));
}

void RunFuncs() {
    Scheduler.Run();
}
