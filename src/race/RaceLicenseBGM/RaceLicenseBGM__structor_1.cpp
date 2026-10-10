#include "gt4/RaceLicenseBGM.h"
extern "C" void RaceBGMPS2__structor_1(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *RaceLicenseBGM__vtable;

extern "C" void RaceLicenseBGM__structor_1(struct RaceLicenseBGM *arg0, int arg1) {
    arg0->unk4 = &RaceLicenseBGM__vtable;
    RaceBGMPS2__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
