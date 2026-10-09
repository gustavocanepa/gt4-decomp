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

struct VEntry_58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(char *o) {
    VEntry_58 *e = (VEntry_58 *)((char *)((VObj_58 *)o)->vtbl + 0x58);
    return e->fn(o + e->delta);
}
extern "C" void func_001DC650(void *);
extern "C" void func_001F60A0(void *, s32, s32);
extern "C" void func_00314B20(void *, void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_00312318(void *, s32);
extern "C" struct S00659988 * func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_001DC5F8(void *, s32);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void func_001E3B00(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    Str s1;
    s32 buf2[4];
    s32 *p_s4;
    Str *p_s3;
    s32 v_s0;
    s32 newVal;
    s32 oldVal;
    if (arg2 > 0) {
        p_s4 = buf2;
        p_s3 = &s1;
        func_001DC650(p_s4);
        v_s0 = *p_s4;
        func_001F60A0(p_s3, v_s0, vcall_58((char *)(*(s32 *)(char *)arg3)));
        func_00314B20(buf0, p_s3);
        if (arg0 != buf0) {
            newVal = buf0[0];
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_00312318(buf0, 0x2);
        str_release(p_s3);
        func_001DC5F8(p_s4, 0x2);
    }
}
