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
extern "C" void func_001B1D88(void *, void *);
extern "C" void func_0043B690(s32, s32, s32);
extern "C" void func_001B1D30(void *, s32);

struct MUsedCar__set_arg3 {
    char pad0[0x4];
    s32 unk4;
};

extern "C" void MUsedCar__set(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 v_s1;
    s32 v_s0;
    if (arg2 >= 0x2) {
        v_s1 = vcall_58((char *)(((struct MUsedCar__set_arg3 *)arg3)->unk4));
        v_s0 = vcall_58((char *)(*(s32 *)(char *)arg3));
        func_001B1D88(buf0, arg1);
        func_0043B690(*(s32 *)((char *)buf0[0] + 0x10), v_s0, v_s1);
        func_001B1D30(buf0, 0x2);
    }
}
