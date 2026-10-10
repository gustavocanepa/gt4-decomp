#include "types.h"
#include "gt4/RaceLanControlManager.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char RaceLanControlManager__vtable[];
void func_0055ED40(void *, s32);
void func_005C1628(void *);
void RaceLanControlManager__structor_1(struct RaceLanControlManager *arg0, s32 arg1) {
    arg0->unk3C = (s32)RaceLanControlManager__vtable;
    func_0055ED40(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
