#include "gt4/RaceChampionshipInformation.h"
typedef int s32;

extern void *RaceChampionshipInformation__vtable;
extern "C" void func_00444210(void *, s32);
extern "C" void RaceInformation__structor_1(void *, s32);
extern "C" void func_005C1628(void *);

extern "C" void RaceChampionshipInformation__structor_1(void *arg0, s32 arg1) {
    ((struct RaceChampionshipInformation *)arg0)->unk12C = &RaceChampionshipInformation__vtable;
    if ((char *)arg0 + 0x180 != 0) {
        char *p0 = (char *)arg0 + 0xab0;
        while ((char *)arg0 + 0x180 != p0) {
            p0 -= 0x188;
            func_00444210(p0, 0x2);
        }
    }
    RaceInformation__structor_1(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_005C1628(arg0);
    }
}
