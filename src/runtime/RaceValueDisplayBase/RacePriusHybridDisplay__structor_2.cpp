#include "gt4/RacePriusHybridDisplay.h"
extern "C" void RaceDisplayObjectBase__structor_1(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *RacePriusHybridDisplay__vtable;

extern "C" void RacePriusHybridDisplay__structor_2(struct RacePriusHybridDisplay *arg0, int arg1) {
    arg0->unk14 = &RacePriusHybridDisplay__vtable;
    RaceDisplayObjectBase__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
