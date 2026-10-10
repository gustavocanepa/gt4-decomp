#include "gt4/mLoggerFace.h"
typedef int s32;

extern void *mLoggerFace__vtable;
extern "C" void func_00228480(void *, s32);
extern "C" void func_001237E0(void *, s32);
extern "C" void mWidget__structor_1(void *, s32);
extern "C" void func_00326798(void *, s32, s32, const char *);

extern "C" void mLoggerFace__structor_1(void *arg0, s32 arg1) {
    ((struct mLoggerFace *)arg0)->unk4 = &mLoggerFace__vtable;
    func_00228480((char *)arg0 + 0xa8, 0x2);
    func_001237E0((char *)arg0 + 0xa4, 0x2);
    mWidget__structor_1(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_00326798(arg0, 0xb0, 0x4, "RefCounter");
    }
}
