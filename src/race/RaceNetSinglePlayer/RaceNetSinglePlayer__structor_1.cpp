#include "gt4/RaceNetSinglePlayer.h"
extern "C" void RaceSinglePlayer__structor_1(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *RaceNetSinglePlayer__vtable;

extern "C" void RaceNetSinglePlayer__structor_1(struct RaceNetSinglePlayer *arg0, int arg1) {
    arg0->unk64 = &RaceNetSinglePlayer__vtable;
    RaceSinglePlayer__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
