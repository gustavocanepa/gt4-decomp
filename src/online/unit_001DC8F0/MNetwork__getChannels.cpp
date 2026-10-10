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
extern "C" void func_001DC650(void *, void *);
extern "C" void func_001F2820(void *, s32, s32, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002ED5C0(void *, s32);
extern "C" void func_001DC5F8(void *, s32);

struct MNetwork__getChannels_arg3 {
    char pad0[0x4];
    s32 unk4;
};

extern "C" void MNetwork__getChannels(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 v_s4;
    s32 v_s0;
    s32 *p_s1;
    s32 newVal;
    s32 oldVal;
    v_s4 = 0x1;
    if (arg2 > 0) {
        v_s4 = vcall_58((char *)(*(s32 *)(char *)arg3));
    }
    v_s0 = 0x10;
    if (!((arg2 < 0x2))) {
        v_s0 = vcall_58((char *)(((struct MNetwork__getChannels_arg3 *)arg3)->unk4));
    }
    p_s1 = buf1;
    func_001DC650(p_s1, arg1);
    func_001F2820(buf0, *p_s1, v_s4, v_s0);
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
    func_002ED5C0(buf0, 0x2);
    func_001DC5F8(p_s1, 0x2);
}
