#include "gt4/RaceGTmodeInformation.h"
typedef int s32;

extern void *RaceGTmodeInformation__vtable;
extern "C" void SPEC_DATABASE__CarEquipments__setVariationOrder(void *, s32);
extern "C" void RaceInformation__structor_1(void *, s32);
extern "C" void func_005C1628(void *);

extern "C" void RaceGTmodeInformation__structor_1(struct RaceGTmodeInformation *arg0, s32 arg1)
{
    arg0->unk12C_pvoid = &RaceGTmodeInformation__vtable;
    SPEC_DATABASE__CarEquipments__setVariationOrder(&arg0->unk130, 2);
    RaceInformation__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
