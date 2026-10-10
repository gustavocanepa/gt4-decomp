#include "gt4/mToolTipFace.h"
typedef int s32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; };
struct S00659988 { const char *name; };

extern void *mToolTipFace__vtable;
extern "C" S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_00203118(void *, s32);
extern "C" void mWidget__structor_1(void *, s32);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

static inline void member_0(char *m) {
    str_release((Str *)(m + 0x10));
    func_00203118(m, 0x2);
}

extern "C" void mToolTipFace__structor_1(void *arg0, s32 arg1) {
    ((struct mToolTipFace *)arg0)->unk4 = &mToolTipFace__vtable;
    str_release((Str *)((char *)arg0 + 0x104));
    func_00203118((char *)arg0 + 0xe0, 0x2);
    member_0((char *)arg0 + 0xa0);
    mWidget__structor_1(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_00326798(arg0, 0x154, 0x4, "RefCounter");
    }
}
