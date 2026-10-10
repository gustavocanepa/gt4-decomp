#include "gt4/mHttp.h"
typedef int s32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; };
struct S00659988 { const char *name; };

extern void *mHttp__vtable;
extern "C" S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_00309378(void *, s32);
extern "C" void func_002F9B38(void *, s32);
extern "C" void func_004E70F0(void *, s32);
extern "C" void hObject__structor_2(void *, s32);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}


extern "C" void mHttp__structor_1(void *arg0, s32 arg1) {
    ((struct mHttp *)arg0)->unk4 = &mHttp__vtable;
    str_release((Str *)((char *)arg0 + 0x104));
    func_00309378((char *)arg0 + 0x100, 0x2);
    func_002F9B38((char *)arg0 + 0xfc, 0x2);
    func_004E70F0((char *)arg0 + 0x10, 0x2);
    hObject__structor_2(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_00326798(arg0, 0x110, 0x4, "RefCounter");
    }
}
