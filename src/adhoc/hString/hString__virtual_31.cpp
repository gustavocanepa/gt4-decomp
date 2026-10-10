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

struct VEntry_18 { s16 delta; s16 index; void (*fn)(void *, void *); };
struct VObj_18 { char pad0[4]; VEntry_18 *vtbl; };
static inline void vcall_18_ret(void *ret, char *o) {
    VEntry_18 *e = (VEntry_18 *)((char *)((VObj_18 *)o)->vtbl + 0x18);
    e->fn(ret, o + e->delta);
}
extern "C" s32 func_005C2A50(void *, void *, s32, s32);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002FC870(void *, s32);
extern "C" struct S00659988 * func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void hString__virtual_31(s32 *arg0, void *arg1, s32 arg2, char **arg3, s32 *arg4) {
    s32 buf0[4];
    Str s1;
    s32 buf2[4];
    Str s3;
    Str *p_s3;
    Str *p_s2;
    s32 newVal;
    s32 oldVal;
    p_s3 = &s1;
    vcall_18_ret((char *)p_s3, (char *)(*(s32 *)(char *)arg2));
    p_s2 = &s3;
    vcall_18_ret((char *)p_s2, (char *)(*(s32 *)(char *)arg4));
    func_002FE278(buf0, ((unsigned)func_005C2A50(p_s3, p_s2, 0, -0x1) >> 31));
    if (arg1 != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *(s32 *)arg1;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *(s32 *)arg1 = newVal;
    }
    func_002FC870(buf0, 0x2);
    str_release(p_s2);
    str_release(p_s3);
}
