#include "gt4/RaceNetBattleInformation.h"
typedef int s32;

extern void *D_00640000;
extern void *RaceNetBattleInformation__vtable;
extern "C" void *func_005F30A0(void *);

extern "C" void RaceNetBattleInformation__structor_0(struct RaceNetBattleInformation *arg0) {
    func_005F30A0(arg0);
    arg0->unkAB8 = (void *)(-0x1);
    arg0->unk12C = &RaceNetBattleInformation__vtable;
    arg0->unk118 = *(void **)((char *)&D_00640000 + 0x6450);
}
