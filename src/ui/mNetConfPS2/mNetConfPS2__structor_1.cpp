#include "gt4/mNetConfPS2.h"
typedef int s32;

extern void *mNetConfPS2__vtable;
extern "C" void *mNetConf__structor_1(void *);

extern "C" void *mNetConfPS2__structor_1(struct mNetConfPS2 *arg0) {
    void *r0 = mNetConf__structor_1(arg0);
    arg0->unk268 = 0x0;
    arg0->unk4 = &mNetConfPS2__vtable;
    arg0->unk26C_pvoid = 0x0;
    arg0->unk270 = 0x0;
    arg0->unk370 = 0x0;
    return r0;
}
