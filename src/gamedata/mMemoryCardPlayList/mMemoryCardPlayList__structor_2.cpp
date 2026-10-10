#include "gt4/mMemoryCardPlayList.h"
typedef int s32;

extern "C" void func_005C1628(void *arg0);
extern "C" void hObject__structor_2(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mMemoryCardPlayList__vtable;

extern "C" void mMemoryCardPlayList__structor_2(struct mMemoryCardPlayList *arg0, s32 arg1) {
    arg0->unk4 = &mMemoryCardPlayList__vtable;
    if (arg0->unk14 != 0) {
        func_005C1628(arg0->unk10);
    }
    hObject__structor_2(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0x1C, 4, "RefCounter");
    }
}
