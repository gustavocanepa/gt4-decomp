#include "gt4/mMBox.h"
typedef int s32;

extern void *mMBox__vtable;
extern "C" void mBox__structor_1(void *, s32);
extern "C" void func_00326798(void *, s32, s32, const char *);

extern "C" void mMBox__structor_1(struct mMBox *arg0, s32 arg1) {
    arg0->unk4_pvoid = &mMBox__vtable;
    mBox__structor_1(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_00326798(arg0, 0xcc, 0x4, "RefCounter");
    }
}
