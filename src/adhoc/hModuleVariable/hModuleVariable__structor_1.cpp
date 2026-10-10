#include "gt4/hModuleVariable.h"
typedef int s32;

extern "C" void func_00323B60(void *arg0, s32 arg1);
extern "C" void func_00309378(void *arg0, s32 arg1);
extern "C" void hVariable__structor_1(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *hModuleVariable__vtable;

extern "C" void hModuleVariable__structor_1(void *arg0, s32 arg1) {
    ((struct hModuleVariable *)arg0)->unk4_pvoid = &hModuleVariable__vtable;
    func_00323B60((char *)arg0 + 0x18, 2);
    func_00309378((char *)arg0 + 0x14, 2);
    hVariable__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x1C, 4, "RefCounter");
    }
}
