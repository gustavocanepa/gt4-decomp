#include "gt4/mModelFace.h"
typedef int s32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; };
struct S00659988 { const char *name; };

extern void *mModelFace__vtable;
extern "C" void func_0021B340(void *, s32);
extern "C" S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_00210710(void *, s32);
extern "C" void func_0021B5D0(void *, s32);
extern "C" void func_00203118(void *, s32);
extern "C" void MModel__structor_1(void *, s32);
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
        char *p2 = m + 0x164;
        while (m + 0x14 != p2) {
            p2 -= 0x54;
            func_00203118((char *)p2 + 0x44, 0x2);
            func_00203118((char *)p2 + 0x34, 0x2);
            func_00203118((char *)p2 + 0x24, 0x2);
            func_00203118((char *)p2 + 0x14, 0x2);
        }
    }
    func_00203118(m + 0x4, 0x2);
}

extern "C" void mModelFace__structor_1(void *arg0, s32 arg1) {
    ((struct mModelFace *)arg0)->unk4 = &mModelFace__vtable;
    func_0021B340((char *)arg0 + 0x2dc, 0x2);
    str_release((Str *)((char *)arg0 + 0x2d8));
    if ((char *)arg0 + 0x2d0 != 0) {
        char *p0 = (char *)arg0 + 0x2d8;
        while ((char *)arg0 + 0x2d0 != p0) {
            p0 -= 0x4;
            func_00210710(p0, 0x2);
        }
    }
    str_release((Str *)((char *)arg0 + 0x2c8));
    if ((char *)arg0 + 0x2c0 != 0) {
        char *p1 = (char *)arg0 + 0x2c8;
        while ((char *)arg0 + 0x2c0 != p1) {
            p1 -= 0x4;
            func_0021B5D0(p1, 0x2);
        }
    }
    str_release((Str *)((char *)arg0 + 0x2b8));
    member_0((char *)arg0 + 0x154);
    MModel__structor_1((char *)arg0 + 0xa0, 0x2);
    mWidget__structor_1(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_00326798(arg0, 0x30c, 0x4, "RefCounter");
    }
}
