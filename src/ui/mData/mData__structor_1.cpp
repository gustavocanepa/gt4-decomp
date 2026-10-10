#include "gt4/mData.h"
typedef int s32;

extern void *mData__vtable;
extern "C" void RefCounter__structor_2(void *, s32);
extern "C" void func_00326798(void *, s32, s32, const char *);

extern "C" void mData__structor_1(struct mData *arg0, s32 arg1) {
    arg0->unk4 = &mData__vtable;
    RefCounter__structor_2(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_00326798(arg0, 0x8, 0x4, "RefCounter");
    }
}
