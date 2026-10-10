#include "gt4/mLogicalOr.h"
typedef int s32;

extern void *mLogicalOr__vtable;
extern "C" void *RefCounter__structor_0(void *);

extern "C" void *mLogicalOr__structor_0(struct mLogicalOr *arg0, s32 arg1) {
    void *r0 = RefCounter__structor_0(arg0);
    arg0->unk4 = &mLogicalOr__vtable;
    arg0->unk8_pvoid = (void *)(arg1);
    return r0;
}
