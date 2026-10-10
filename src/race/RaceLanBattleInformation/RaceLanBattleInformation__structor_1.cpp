#include "gt4/RaceLanBattleInformation.h"
typedef int s32;

extern "C" void func_005F3118(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *RaceLanBattleInformation__vtable;

extern "C" void RaceLanBattleInformation__structor_1(struct RaceLanBattleInformation *arg0, s32 arg1) {
    arg0->unk12C_pvoid = &RaceLanBattleInformation__vtable;
    func_005F3118(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
