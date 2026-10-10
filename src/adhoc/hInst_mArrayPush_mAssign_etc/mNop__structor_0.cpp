#include "gt4/mNop.h"
typedef int s32;

extern void *mNop__vtable;
extern "C" void *RefCounter__structor_0(void *);

extern "C" void *mNop__structor_0(struct mNop *arg0, s32 arg1) {
    void *r0 = RefCounter__structor_0(arg0);
    arg0->unk4 = &mNop__vtable;
    arg0->unk8 = (void *)(arg1);
    return r0;
}
