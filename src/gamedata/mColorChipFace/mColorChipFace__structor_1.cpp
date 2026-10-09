typedef int s32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; };
struct S00659988 { const char *name; };

extern void *mColorChipFace__vtable;
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


extern "C" void mColorChipFace__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x4) = &mColorChipFace__vtable;
    if ((char *)arg0 + 0xa8 != 0) {
        char *p0 = (char *)arg0 + 0xb0;
        while ((char *)arg0 + 0xa8 != p0) {
            p0 -= 0x4;
            func_00210710(p0, 0x2);
        }
    }
    if ((char *)arg0 + 0xa0 != 0) {
        char *p1 = (char *)arg0 + 0xa8;
        while ((char *)arg0 + 0xa0 != p1) {
            p1 -= 0x4;
            str_release((Str *)(p1));
        }
    }
    mWidget__structor_1(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_00326798(arg0, 0xdc, 0x4, "RefCounter");
    }
}
