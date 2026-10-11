#include "gt4/mPlayerStats.h"
typedef int s32;

extern void *mPlayerStats__vtable;
extern "C" void *hObject__structor_0(void *);
extern "C" void *memcpy(void *, void *, void *);

extern "C" void mPlayerStats__structor_0(void *arg0, void *arg1) {
    hObject__structor_0(arg0);
    ((struct mPlayerStats *)arg0)->unk4 = &mPlayerStats__vtable;
    memcpy((char *)arg0 + 0x10, *(void **)(arg1), *(void **)((char *)*(void **)(arg1) + -0x10));
    ((struct mPlayerStats *)arg0)->unk4F = 0x0;
    ((struct mPlayerStats *)arg0)->unk6F = 0x0;
    ((struct mPlayerStats *)arg0)->unk8F = 0x0;
    ((struct mPlayerStats *)arg0)->unkCF = 0x0;
    ((struct mPlayerStats *)arg0)->unk10F = 0x0;
}
