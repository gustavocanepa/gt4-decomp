#include "gt4/mStringPush.h"
typedef int s32;

extern void *mStringPush__vtable;
extern "C" void *RefCounter__structor_0(void *);

extern "C" void *mStringPush__structor_0(struct mStringPush *arg0, s32 arg1) {
    void *r0 = RefCounter__structor_0(arg0);
    arg0->unk4 = &mStringPush__vtable;
    arg0->unk8 = (void *)(arg1);
    return r0;
}
