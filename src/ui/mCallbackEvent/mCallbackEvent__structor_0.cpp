#include "gt4/mCallbackEvent.h"
typedef int s32;

extern void *mCallbackEvent__vtable;
extern "C" void *mEvent__structor_0(void *);

extern "C" void *mCallbackEvent__structor_0(struct mCallbackEvent *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *r0 = mEvent__structor_0(arg0);
    arg0->unk4 = &mCallbackEvent__vtable;
    arg0->unk20 = (void *)(arg3);
    return r0;
}
