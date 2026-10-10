#include "gt4/mCall.h"
typedef int s32;

extern void *mCall__vtable;
extern "C" void *RefCounter__structor_0(void *);

extern "C" void *mCall__structor_0(struct mCall *arg0, s32 arg1) {
    void *r0 = RefCounter__structor_0(arg0);
    arg0->unk4 = &mCall__vtable;
    arg0->unk8 = (void *)(arg1);
    return r0;
}
