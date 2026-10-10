#include "gt4/hValue.h"
typedef int s32;

extern "C" void RefCounter__structor_2(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *hValue__vtable;

extern "C" void hValue__structor_1(struct hValue *arg0, s32 arg1) {
    arg0->unk4_pvoid = &hValue__vtable;
    RefCounter__structor_2(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0xC, 4, "RefCounter");
    }
}
