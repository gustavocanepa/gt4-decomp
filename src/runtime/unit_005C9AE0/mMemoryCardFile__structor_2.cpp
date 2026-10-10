#include "gt4/mMemoryCardFile.h"
typedef int s32;

extern void *mMemoryCardFile__vtable;
extern "C" void hObject__structor_2(void *, s32);
extern "C" void func_00326798(void *, s32, s32, const char *);
struct VEntry_vcall_0 { short delta; short index; void (*fn)(void *, s32); };
static inline void vcall_0(char *o, s32 a0) {
    VEntry_vcall_0 *e = (VEntry_vcall_0 *)(*(char **)(o + 0x4c) + 0x8);
    e->fn(o + e->delta, a0);
}

extern "C" void mMemoryCardFile__structor_2(void *arg0, s32 arg1) {
    ((struct mMemoryCardFile *)arg0)->unk4 = &mMemoryCardFile__vtable;
    if (((struct mMemoryCardFile *)arg0)->unk14 != 0) {
        if (((struct mMemoryCardFile *)arg0)->unk10 != 0) {
            vcall_0((char *)*(void **)((char *)arg0 + 0x10), 0x3);
        }
    }
    hObject__structor_2(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_00326798(arg0, 0x18, 0x4, "RefCounter");
    }
}
