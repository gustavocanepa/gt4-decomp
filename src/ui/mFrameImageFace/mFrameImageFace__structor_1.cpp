typedef int s32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; };
struct S00659988 { const char *name; };

extern void *mFrameImageFace__vtable;
extern "C" void func_00210710(void *, s32);
extern "C" S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void mImageFace__structor_1(void *, s32);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}


extern "C" void mFrameImageFace__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x4) = &mFrameImageFace__vtable;
    func_00210710((char *)arg0 + 0x12c, 0x2);
    func_00210710((char *)arg0 + 0x128, 0x2);
    func_00210710((char *)arg0 + 0x124, 0x2);
    func_00210710((char *)arg0 + 0x120, 0x2);
    func_00210710((char *)arg0 + 0x11c, 0x2);
    func_00210710((char *)arg0 + 0x118, 0x2);
    func_00210710((char *)arg0 + 0x114, 0x2);
    func_00210710((char *)arg0 + 0x110, 0x2);
    str_release((Str *)((char *)arg0 + 0x10c));
    str_release((Str *)((char *)arg0 + 0x108));
    str_release((Str *)((char *)arg0 + 0x104));
    str_release((Str *)((char *)arg0 + 0x100));
    str_release((Str *)((char *)arg0 + 0xfc));
    str_release((Str *)((char *)arg0 + 0xf8));
    str_release((Str *)((char *)arg0 + 0xf4));
    str_release((Str *)((char *)arg0 + 0xf0));
    mImageFace__structor_1(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_00326798(arg0, 0x138, 0x4, "RefCounter");
    }
}
