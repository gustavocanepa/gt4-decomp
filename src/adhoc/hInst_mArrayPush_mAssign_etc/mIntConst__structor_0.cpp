#include "gt4/mIntConst.h"
typedef int s32;

extern void *mIntConst__vtable;
extern "C" void *RefCounter__structor_0(void *);

extern "C" void *mIntConst__structor_0(struct mIntConst *arg0, s32 arg1) {
    void *r0 = RefCounter__structor_0(arg0);
    arg0->unk4 = &mIntConst__vtable;
    arg0->unk8 = (void *)(arg1);
    return r0;
}
