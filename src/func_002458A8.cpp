typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct S00659988 {
    const char *name;
};

extern "C" void func_00263420(void);
extern "C" void func_002B71D0(void *, s32);
extern "C" void func_00245270(void *, void *);
extern "C" struct S00659988 * func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" s32 func_002B7110(s32);
extern "C" void func_002450E8(void *, s32);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void func_002458A8(s32 *arg0) {
    Str s0;
    char *v_s3;
    v_s3 = (char *)arg0 + 0x104;
    func_00263420();
    func_002B71D0(&s0, *(s32 *)(char *)v_s3);
    func_00245270(arg0, &s0);
    str_release(&s0);
    func_002450E8(arg0, func_002B7110(*(s32 *)(char *)v_s3));
}
