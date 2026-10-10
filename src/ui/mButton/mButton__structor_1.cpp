#include "gt4/mButton.h"
typedef int s32;

extern "C" void func_002F9B38(void *arg0, s32 arg1);
extern "C" void mComposite__structor_1(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mButton__vtable;

extern "C" void mButton__structor_1(void *arg0, s32 arg1) {
    ((struct mButton *)arg0)->unk4_pvoid = &mButton__vtable;
    func_002F9B38((char *)arg0 + 0xB0, 2);
    mComposite__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0xB4, 4, "RefCounter");
    }
}
