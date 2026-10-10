#include "gt4/mTryCatch.h"
typedef int s32;

extern void *mTryCatch__vtable;
extern "C" void *RefCounter__structor_0(void *);

extern "C" void *mTryCatch__structor_0(struct mTryCatch *arg0, s32 arg1) {
    void *r0 = RefCounter__structor_0(arg0);
    arg0->unk4 = &mTryCatch__vtable;
    arg0->unk8_pvoid = (void *)(arg1);
    return r0;
}
