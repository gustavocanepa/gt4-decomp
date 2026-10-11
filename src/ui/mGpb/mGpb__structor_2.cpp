#include "gt4/mGpb.h"
typedef int s32;

extern "C" void free(void *arg0);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);
extern "C" void func_0048F448(void *);
extern "C" void func_0048F2B0(void *, s32);
extern "C" void hObject__structor_2(void *, s32);

extern void *mGpb__vtable;

extern "C" void mGpb__structor_2(void *arg0, s32 arg1) {
    ((struct mGpb *)arg0)->unk4 = &mGpb__vtable;
    func_0048F448((char *)arg0 + 0x10);
    func_0048F2B0((char *)arg0 + 0x10, 2);
    hObject__structor_2(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x18, 4, "RefCounter");
    }
}
