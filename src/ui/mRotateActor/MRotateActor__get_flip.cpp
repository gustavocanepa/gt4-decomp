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
extern "C" void * func_002CC920(void *);
extern "C" void func_002CC8C8(void *, s32);
extern "C" void * func_002FE278(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002FC870(void *, s32);

extern "C" void MRotateActor__get_flip(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 v_s0;
    s32 *p_s1;
    s32 newVal;
    s32 oldVal;
    if (arg2 > 0) {
        func_002CC920(buf0);
        v_s0 = buf0[0];
        *(s32 *)((char *)v_s0 + 0x3c) = vcall_58((char *)*(s32 *)arg3) != 0;
        func_002CC8C8(buf0, 0x2);
    } else {
        p_s1 = buf1;
        func_002CC920(p_s1);
        func_002FE278(buf0, *(s32 *)((char *)*p_s1 + 0x3c));
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
        func_002CC8C8(p_s1, 0x2);
    }
}
