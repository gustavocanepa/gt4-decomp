#include "gt4/RaceSolitaireInformation.h"
typedef int s32;

extern void *RaceSolitaireInformation__vtable;
extern "C" void func_003D62A8(void *, s32);
extern "C" void RaceInformation__structor_1(void *, s32);
extern "C" void func_005C1628(void *);

extern "C" void RaceSolitaireInformation__structor_1(struct RaceSolitaireInformation *arg0, s32 arg1)
{
    arg0->unk12C = &RaceSolitaireInformation__vtable;
    func_003D62A8(&arg0->unk130, 2);
    RaceInformation__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
