#include "gt4/RaceArcadeDemoInformation.h"
typedef int s32;

extern "C" void RaceArcadeInformation__structor_1(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *RaceArcadeDemoInformation__vtable;

extern "C" void RaceArcadeDemoInformation__structor_1(struct RaceArcadeDemoInformation *arg0, s32 arg1) {
    arg0->unk12C_pvoid = &RaceArcadeDemoInformation__vtable;
    RaceArcadeInformation__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
