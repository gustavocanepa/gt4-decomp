#include "gt4/RaceCrewModel.h"
typedef int s32;

extern void *RaceCrewModel__vtable;
extern "C" void RaceDriverModel__structor_1(void *, s32);
extern "C" void func_005C1628(void *);

extern "C" void RaceCrewModel__structor_2(struct RaceCrewModel *arg0, s32 arg1) {
    arg0->unk7DC_pvoid = &RaceCrewModel__vtable;
    RaceDriverModel__structor_1(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_005C1628(arg0);
    }
}
