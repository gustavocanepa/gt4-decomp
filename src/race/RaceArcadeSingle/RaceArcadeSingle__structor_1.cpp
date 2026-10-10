#include "gt4/RaceArcadeSingle.h"
extern "C" void DynamicsConductorSinglePlayer__structor_2(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *RaceArcadeSingle__vtable;

extern "C" void RaceArcadeSingle__structor_1(struct RaceArcadeSingle *arg0, int arg1) {
    arg0->unk64 = &RaceArcadeSingle__vtable;
    DynamicsConductorSinglePlayer__structor_2(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
