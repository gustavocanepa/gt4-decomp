#include "gt4/RaceSplitBattleInformation.h"
typedef int s32;

extern "C" void func_005F2940(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *RaceSplitBattleInformation__vtable;

extern "C" void RaceSplitBattleInformation__structor_1(struct RaceSplitBattleInformation *arg0, s32 arg1) {
    arg0->unk12C_pvoid = &RaceSplitBattleInformation__vtable;
    func_005F2940(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
