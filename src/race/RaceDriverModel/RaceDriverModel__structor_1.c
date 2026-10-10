#include "types.h"
#include "gt4/RaceDriverModel.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char RaceDriverModel__vtable[];
void HumanModel__structor_1(void *, s32);
void func_005C1628(void *);
void RaceDriverModel__structor_1(struct RaceDriverModel *arg0, s32 arg1) {
    arg0->unk7DC = (s32)RaceDriverModel__vtable;
    HumanModel__structor_1(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
