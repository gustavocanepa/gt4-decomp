#include "gt4/mLocalizedText.h"
typedef int s32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; };
struct S00659988 { const char *name; };

extern void *mLocalizedText__vtable;
extern "C" S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void RefCounter__structor_2(void *, s32);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}


extern "C" void mLocalizedText__structor_1(void *arg0, s32 arg1) {
    ((struct mLocalizedText *)arg0)->unk4 = &mLocalizedText__vtable;
    str_release((Str *)((char *)arg0 + 0xc));
    str_release((Str *)((char *)arg0 + 0x8));
    RefCounter__structor_2(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_00326798(arg0, 0x10, 0x4, "RefCounter");
    }
}
