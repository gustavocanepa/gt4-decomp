#include "gt4/RaceNetRallyBattleInformation.h"
typedef int s32;

extern "C" void RaceNetSinglePlayerInformation__structor_1(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *RaceNetRallyBattleInformation__vtable;

extern "C" void RaceNetRallyBattleInformation__structor_1(struct RaceNetRallyBattleInformation *arg0, s32 arg1) {
    arg0->unk12C_pvoid = &RaceNetRallyBattleInformation__vtable;
    RaceNetSinglePlayerInformation__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
