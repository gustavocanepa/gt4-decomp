#include "gt4/hFunctionObject.h"
typedef int s32;

extern "C" void func_002FA8D0(void *arg0, s32 arg1);
extern "C" void hObject__structor_2(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *hFunctionObject__vtable;

extern "C" void hFunctionObject__structor_1(void *arg0, s32 arg1) {
    ((struct hFunctionObject *)arg0)->unk4_pvoid = &hFunctionObject__vtable;
    func_002FA8D0((char *)arg0 + 0x10, 2);
    hObject__structor_2(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x14, 4, "RefCounter");
    }
}
