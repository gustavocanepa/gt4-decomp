#include "gt4/RaceABMonitor.h"
typedef int s32;

extern void *RaceABMonitor__vtable;
extern "C" void RaceDisplayObjectBase__structor_1(void *, s32);
extern "C" void func_005C1628(void *);
struct VEntry_vcall_0 { short delta; short index; void (*fn)(void *, s32); };
static inline void vcall_0(char *o, s32 a0) {
    VEntry_vcall_0 *e = (VEntry_vcall_0 *)(*(char **)(o + 0x14) + 0x8);
    e->fn(o + e->delta, a0);
}

extern "C" void RaceABMonitor__structor_2(void *arg0, s32 arg1) {
    ((struct RaceABMonitor *)arg0)->unk14 = &RaceABMonitor__vtable;
    if ((char *)arg0 + 0x20 != 0) {
        char *p0 = (char *)arg0 + 0x80;
        while ((char *)arg0 + 0x20 != p0) {
            p0 -= 0x30;
            vcall_0((char *)p0, 0x2);
        }
    }
    RaceDisplayObjectBase__structor_1(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_005C1628(arg0);
    }
}
