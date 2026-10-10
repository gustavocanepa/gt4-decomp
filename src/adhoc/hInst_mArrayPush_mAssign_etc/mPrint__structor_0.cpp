#include "gt4/mPrint.h"
typedef int s32;

extern void *mPrint__vtable;
extern "C" void *RefCounter__structor_0(void *);

extern "C" void *mPrint__structor_0(struct mPrint *arg0, s32 arg1) {
    void *r0 = RefCounter__structor_0(arg0);
    arg0->unk4 = &mPrint__vtable;
    arg0->unk8 = (void *)(arg1);
    return r0;
}
