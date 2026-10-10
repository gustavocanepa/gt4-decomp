#include "gt4/mLogicalAnd.h"
typedef int s32;

extern void *mLogicalAnd__vtable;
extern "C" void *RefCounter__structor_0(void *);

extern "C" void *mLogicalAnd__structor_0(struct mLogicalAnd *arg0, s32 arg1) {
    void *r0 = RefCounter__structor_0(arg0);
    arg0->unk4 = &mLogicalAnd__vtable;
    arg0->unk8_pvoid = (void *)(arg1);
    return r0;
}
