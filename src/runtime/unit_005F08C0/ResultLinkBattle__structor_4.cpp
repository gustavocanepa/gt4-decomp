#include "gt4/ResultLinkBattle.h"
extern "C" void RaceResultBase__structor_0(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *ResultLinkBattle__vtable;

extern "C" void ResultLinkBattle__structor_4(struct ResultLinkBattle *arg0, int arg1) {
    arg0->unkC = &ResultLinkBattle__vtable;
    RaceResultBase__structor_0(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
