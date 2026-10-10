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
extern "C" void * func_001B1D88(void *);
extern "C" void func_001B1D30(void *, s32);
extern "C" void * func_002FE278(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002FC870(void *, s32);

struct func_001B20B8_v_s0 {
    char pad0[0x24];
    s32 unk24;
};

extern "C" void func_001B20B8(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 v_s0;
    s32 t1;
    s32 *p_s2;
    s32 newVal;
    s32 oldVal;
    if (arg2 > 0) {
        func_001B1D88(buf0);
        v_s0 = *(s32 *)((char *)buf0[0] + 0x10);
        t1 = vcall_58((char *)(*(s32 *)(char *)arg3));
        ((struct func_001B20B8_v_s0 *)v_s0)->unk24 = t1;
        func_001B1D30(buf0, 0x2);
    } else {
        p_s2 = buf1;
        func_001B1D88(p_s2);
        func_002FE278(buf0, *(s32 *)((char *)(*(s32 *)((char *)(*p_s2) + 0x10)) + 0x24));
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
        func_002FC870(buf0, 0x2);
        func_001B1D30(p_s2, 0x2);
    }
}
