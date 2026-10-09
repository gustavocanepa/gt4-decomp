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

struct VEntry_1d0 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_1d0 { char pad0[4]; VEntry_1d0 *vtbl; };
static inline s32 vcall_1d0(char *o) {
    VEntry_1d0 *e = (VEntry_1d0 *)((char *)((VObj_1d0 *)o)->vtbl + 0x1d0);
    return e->fn(o + e->delta);
}
extern "C" void func_00221B28(void *);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002FC870(void *, s32);
extern "C" void func_00221AD0(void *, s32);

extern "C" void MNetConf__get_use_auth(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s2;
    s32 t1;
    s32 newVal;
    s32 oldVal;
    func_00221B28(buf0);
    t1 = vcall_1d0((char *)buf0[0]);
    p_s2 = buf1;
    func_002FE278(p_s2, t1);
    if (arg0 != p_s2) {
        newVal = *p_s2;
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *arg0 = newVal;
    }
    func_002FC870(p_s2, 0x2);
    func_00221AD0(buf0, 0x2);
}
