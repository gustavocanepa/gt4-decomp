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
extern "C" void func_0013BDC0(void *, void *);
extern "C" s32 func_00147D80(s32);
extern "C" void func_00440FB8(s32, s32, s32, s32);
extern "C" void func_0013BD68(void *, s32);

struct MCarGarage__makeUsed_arg3 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
};

extern "C" void MCarGarage__makeUsed(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 v_s4;
    s32 v_s2;
    s32 v_s0;
    if (arg2 > 0) {
        v_s4 = -0x1;
        if (!((arg2 < 0x2))) {
            v_s4 = vcall_58((char *)(((struct MCarGarage__makeUsed_arg3 *)arg3)->unk4));
        }
        v_s2 = -0x1;
        if (!((arg2 < 0x3))) {
            v_s2 = vcall_58((char *)(((struct MCarGarage__makeUsed_arg3 *)arg3)->unk8));
        }
        v_s0 = vcall_58((char *)(*(s32 *)(char *)arg3));
        func_0013BDC0(buf0, arg1);
        func_00440FB8(func_00147D80(buf0[0]), v_s0, v_s4, v_s2);
        func_0013BD68(buf0, 0x2);
    }
}
