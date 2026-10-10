#include "gt4/hLocalVariable.h"
typedef int s32;

extern "C" void func_00309378(void *arg0, s32 arg1);
extern "C" void hVariable__structor_1(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *hLocalVariable__vtable;

extern "C" void hLocalVariable__structor_1(void *arg0, s32 arg1) {
    ((struct hLocalVariable *)arg0)->unk4_pvoid = &hLocalVariable__vtable;
    func_00309378((char *)arg0 + 0x14, 2);
    hVariable__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x18, 4, "RefCounter");
    }
}
