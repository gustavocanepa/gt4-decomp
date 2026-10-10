#include "gt4/hBuiltinAttribute.h"
typedef int s32;

extern "C" void hValue__structor_1(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *hBuiltinAttribute__vtable;

extern "C" void hBuiltinAttribute__structor_1(struct hBuiltinAttribute *arg0, s32 arg1) {
    arg0->unk4_pvoid = &hBuiltinAttribute__vtable;
    hValue__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x14, 4, "RefCounter");
    }
}
