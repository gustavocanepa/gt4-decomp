#include "gt4/mSetState.h"
typedef int s32;

extern void *mSetState__vtable;
extern "C" void *RefCounter__structor_0(void *);

extern "C" void *mSetState__structor_0(struct mSetState *arg0, s32 arg1) {
    void *r0 = RefCounter__structor_0(arg0);
    arg0->unk4 = &mSetState__vtable;
    arg0->unk8_pvoid = (void *)(arg1);
    return r0;
}
