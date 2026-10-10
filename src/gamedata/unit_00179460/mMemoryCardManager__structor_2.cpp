#include "gt4/mMemoryCardManager.h"
typedef int s32;

extern void *mMemoryCardManager__vtable;
extern "C" void func_001D2518(void *, s32);
extern "C" void func_00228480(void *, s32);
extern "C" void hObject__structor_2(void *, s32);
extern "C" void func_00326798(void *, s32, s32, const char *);
struct VEntry_vcall_0 { short delta; short index; void (*fn)(void *, s32); };
static inline void vcall_0(char *o, s32 a0) {
    VEntry_vcall_0 *e = (VEntry_vcall_0 *)(*(char **)(o + 0x0) + 0x8);
    e->fn(o + e->delta, a0);
}
struct VEntry_vcall_1 { short delta; short index; void (*fn)(void *, s32); };
static inline void vcall_1(char *o, s32 a0) {
    VEntry_vcall_1 *e = (VEntry_vcall_1 *)(*(char **)(o + 0x4c) + 0x8);
    e->fn(o + e->delta, a0);
}
static inline void member_0(char *m) {
    if (*(void **)(m) != 0) {
        func_001D2518(*(void **)(m), 0x3);
    }
    *(void **)(m) = 0x0;
}
static inline void member_1(char *m) {
    if (*(void **)(m) != 0) {
        vcall_0((char *)*(void **)(m), 0x3);
    }
    *(void **)(m) = 0x0;
}

extern "C" void mMemoryCardManager__structor_2(void *arg0, s32 arg1) {
    ((struct mMemoryCardManager *)arg0)->unk4 = &mMemoryCardManager__vtable;
    member_0((char *)arg0 + 0x20);
    member_1((char *)arg0 + 0x1c);
    if (((struct mMemoryCardManager *)arg0)->unk24 != 0) {
        vcall_1((char *)*(void **)((char *)arg0 + 0x24), 0x3);
    }
    if (((struct mMemoryCardManager *)arg0)->unk20 != 0) {
        func_001D2518(((struct mMemoryCardManager *)arg0)->unk20, 0x3);
    }
    if (((struct mMemoryCardManager *)arg0)->unk1C != 0) {
        vcall_0((char *)*(void **)((char *)arg0 + 0x1c), 0x3);
    }
    if (((struct mMemoryCardManager *)arg0)->unk18 != 0) {
        vcall_1((char *)*(void **)((char *)arg0 + 0x18), 0x3);
    }
    func_00228480((char *)arg0 + 0x10, 0x2);
    hObject__structor_2(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_00326798(arg0, 0x34, 0x4, "RefCounter");
    }
}
