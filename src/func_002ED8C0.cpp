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
extern "C" void func_002ED618(void *);
extern "C" void func_002F0138(s32, s32, s32);
extern "C" void func_002ED5C0(void *, s32);

extern "C" void func_002ED8C0(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 v_s1;
    s32 v_s0;
    if (arg2 == 0x2) {
        func_002ED618(buf0);
        v_s1 = buf0[0];
        v_s0 = vcall_58((char *)(*(s32 *)(char *)arg3));
        func_002F0138(v_s1, v_s0, vcall_58((char *)(*(s32 *)((char *)arg3 + 0x4))));
        func_002ED5C0(buf0, 0x2);
    }
}
