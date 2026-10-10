#include "gt4/mCarFace.h"
typedef int s32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; };
struct S00659988 { const char *name; };

extern void *mCarFace__vtable;
extern "C" void func_0021CA90(void *, s32);
extern "C" void func_0013BD68(void *, s32);
extern "C" void func_00151830(void *, s32);
extern "C" void func_00203118(void *, s32);
extern "C" void func_00210710(void *, s32);
extern "C" S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void mWidget__structor_1(void *, s32);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

static inline void member_0(char *m) {
    if ((char *)m + 0x14 != 0) {
        char *p0 = m + 0x164;
        while (m + 0x14 != p0) {
            p0 -= 0x54;
            func_00203118((char *)p0 + 0x44, 0x2);
            func_00203118((char *)p0 + 0x34, 0x2);
            func_00203118((char *)p0 + 0x24, 0x2);
            func_00203118((char *)p0 + 0x14, 0x2);
        }
    }
    func_00203118(m + 0x4, 0x2);
}

extern "C" void mCarFace__structor_1(void *arg0, s32 arg1) {
    ((struct mCarFace *)arg0)->unk4 = &mCarFace__vtable;
    func_0021CA90((char *)arg0 + 0x2ac, 0x2);
    func_0013BD68((char *)arg0 + 0x2a8, 0x2);
    func_00151830((char *)arg0 + 0x2a4, 0x2);
    member_0((char *)arg0 + 0x138);
    func_00210710((char *)arg0 + 0xcc, 0x2);
    str_release((Str *)((char *)arg0 + 0xa0));
    mWidget__structor_1(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_00326798(arg0, 0x2bc, 0x4, "RefCounter");
    }
}
