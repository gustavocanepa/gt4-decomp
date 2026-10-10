#include "gt4/mMovie.h"
typedef int s32;

extern "C" void RefCounter__structor_2(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);

extern void *mMovie__vtable;

extern "C" void mMovie__structor_1(struct mMovie *arg0, s32 arg1) {
    arg0->unk4 = &mMovie__vtable;
    RefCounter__structor_2(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 8, 4, "RefCounter");
    }
}
