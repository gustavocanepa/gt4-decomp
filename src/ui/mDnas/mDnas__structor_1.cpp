#include "gt4/mDnas.h"
typedef int s32;

extern "C" void free(void *arg0);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);
extern "C" void func_0032EE90(void *);
extern "C" void hObject__structor_2(void *, s32);

extern void *mDnas__vtable;

extern "C" void mDnas__structor_1(void *arg0, s32 arg1) {
    ((struct mDnas *)arg0)->unk4_pvoid = &mDnas__vtable;
    func_0032EE90((char *)arg0 + 0x10);
    hObject__structor_2(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x38, 4, "RefCounter");
    }
}
