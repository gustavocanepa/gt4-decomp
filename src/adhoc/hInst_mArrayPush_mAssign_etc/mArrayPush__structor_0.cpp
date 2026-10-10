#include "gt4/mArrayPush.h"
typedef int s32;

extern void *mArrayPush__vtable;
extern "C" void *RefCounter__structor_0(void *);

extern "C" void *mArrayPush__structor_0(struct mArrayPush *arg0, s32 arg1) {
    void *r0 = RefCounter__structor_0(arg0);
    arg0->unk4 = &mArrayPush__vtable;
    arg0->unk8 = (void *)(arg1);
    return r0;
}
