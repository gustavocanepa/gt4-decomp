#include "gt4/rbuf.h"
typedef int s32;

extern void *rbuf__vtable;
extern "C" void func_005547F8(void *);
extern "C" void func_00575DA0(void *);
extern "C" void func_005C1628(void *);
struct VEntry_vcall_0 { short delta; short index; void (*fn)(void *, s32); };
static inline void vcall_0(char *o, s32 a0) {
    VEntry_vcall_0 *e = (VEntry_vcall_0 *)(*(char **)(o + 0x1c) + 0x8);
    e->fn(o + e->delta, a0);
}

extern "C" void rbuf__structor_1(struct rbuf *arg0, s32 arg1) {
    arg0->unk40 = &rbuf__vtable;
    func_005547F8(arg0);
    if (*(void **)(arg0) != 0) {
        vcall_0((char *)*(void **)(arg0), 0x3);
    }
    func_00575DA0(arg0->unk1C);
    if ((arg1 & 0x1) != 0) {
        return func_005C1628(arg0);
    }
}
