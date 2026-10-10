#include "gt4/mScriptWatcher.h"
typedef int s32;

extern "C" void func_002F9B38(void *arg0, s32 arg1);
extern "C" void mWatcher__structor_1(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mScriptWatcher__vtable;

extern "C" void mScriptWatcher__structor_1(void *arg0, s32 arg1) {
    ((struct mScriptWatcher *)arg0)->unk4_pvoid = &mScriptWatcher__vtable;
    func_002F9B38((char *)arg0 + 0x20, 2);
    mWatcher__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x28, 4, "RefCounter");
    }
}
