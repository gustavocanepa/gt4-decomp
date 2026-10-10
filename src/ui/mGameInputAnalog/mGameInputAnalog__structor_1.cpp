#include "gt4/mGameInputAnalog.h"
typedef int s32;

extern void *mGameInputAnalog__vtable;
extern "C" void hObject__structor_2(void *, s32);
extern "C" void func_00326798(void *, s32, s32, const char *);

extern "C" void mGameInputAnalog__structor_1(struct mGameInputAnalog *arg0, s32 arg1) {
    arg0->unk4_pvoid = &mGameInputAnalog__vtable;
    hObject__structor_2(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_00326798(arg0, 0x54, 0x4, "RefCounter");
    }
}
