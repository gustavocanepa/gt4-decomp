#include "gt4/mEyetoyFace.h"
typedef int s32;

extern void *mEyetoyFace__vtable;
extern "C" void func_001B8248(void *, s32);
extern "C" void func_001B9BE8(void *, s32);
extern "C" void mWidget__structor_1(void *, s32);
extern "C" void func_00326798(void *, s32, s32, const char *);

extern "C" void mEyetoyFace__structor_1(void *arg0, s32 arg1) {
    ((struct mEyetoyFace *)arg0)->unk4_pvoid = &mEyetoyFace__vtable;
    func_001B8248((char *)arg0 + 0xa4, 0x2);
    func_001B9BE8((char *)arg0 + 0xa0, 0x2);
    mWidget__structor_1(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_00326798(arg0, 0xac, 0x4, "RefCounter");
    }
}
