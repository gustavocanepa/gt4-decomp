#include "types.h"
#include "gt4/RaceInformation.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char RaceInformation__vtable[];
void func_00446FC8(void *, s32);
void func_005C1628(void *);
void RaceInformation__structor_1(struct RaceInformation *arg0, s32 arg1) {
    arg0->unk12C = (s32)RaceInformation__vtable;
    func_00446FC8(arg0, 2);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
