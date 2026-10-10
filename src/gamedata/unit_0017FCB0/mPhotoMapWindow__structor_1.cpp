#include "gt4/mPhotoMapWindow.h"
typedef int s32;

extern "C" void func_002F9B38(void *arg0, s32 arg1);
extern "C" void mBox__structor_1(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mPhotoMapWindow__vtable;

extern "C" void mPhotoMapWindow__structor_1(void *arg0, s32 arg1) {
    ((struct mPhotoMapWindow *)arg0)->unk4 = &mPhotoMapWindow__vtable;
    func_002F9B38((char *)arg0 + 0xE4, 2);
    mBox__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x164, 4, "RefCounter");
    }
}
