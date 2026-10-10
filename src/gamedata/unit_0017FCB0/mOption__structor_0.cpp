#include "gt4/mOption.h"
typedef int s32;

extern "C" void *hObject__structor_0(void *arg0);
extern "C" void *func_00436278(void *arg0);
extern "C" char mOption__vtable[];

extern "C" void *mOption__structor_0(struct mOption *arg0) {
    struct mOption *s0 = arg0;
    void *temp_a0;

    hObject__structor_0(s0);
    temp_a0 = (char *)s0 + 0x18;
    s0->unk10_pvoid = temp_a0;
    s0->unk4_pvoid = mOption__vtable;
    return func_00436278(temp_a0);
}
