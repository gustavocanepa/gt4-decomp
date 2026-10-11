#include "gt4/mOptionMenu.h"
typedef int s32;

extern "C" void free(void *arg0);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);
extern "C" void func_002F9B38(void *, s32);
extern "C" void mFBox__structor_1(void *, s32);

extern void *mOptionMenu__vtable;

extern "C" void mOptionMenu__structor_1(void *arg0, s32 arg1) {
    ((struct mOptionMenu *)arg0)->unk4 = &mOptionMenu__vtable;
    func_002F9B38((char *)arg0 + 0xD4, 2);
    func_002F9B38((char *)arg0 + 0xD0, 2);
    func_002F9B38((char *)arg0 + 0xCC, 2);
    mFBox__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x120, 4, "RefCounter");
    }
}
