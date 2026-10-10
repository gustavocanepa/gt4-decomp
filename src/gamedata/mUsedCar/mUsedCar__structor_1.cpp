#include "gt4/mUsedCar.h"
typedef int s32;

extern "C" void hObject__structor_2(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mUsedCar__vtable;

extern "C" void mUsedCar__structor_1(struct mUsedCar *arg0, s32 arg1) {
    arg0->unk4 = &mUsedCar__vtable;
    hObject__structor_2(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x14, 4, "RefCounter");
    }
}
