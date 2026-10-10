#include "gt4/hInt.h"
typedef int s32;

extern void *hInt__vtable;
extern "C" void *hObject__structor_0(void *);

extern "C" void *hInt__structor_0(struct hInt *arg0, s32 arg1) {
    void *r0 = hObject__structor_0(arg0);
    arg0->unk4 = &hInt__vtable;
    arg0->unk10_pvoid = (void *)(arg1);
    return r0;
}
