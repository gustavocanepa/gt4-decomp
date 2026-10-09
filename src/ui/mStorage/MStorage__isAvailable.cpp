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

struct VEntry_198 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_198 { char pad0[4]; VEntry_198 *vtbl; };
static inline s32 vcall_198(char *o) {
    VEntry_198 *e = (VEntry_198 *)((char *)((VObj_198 *)o)->vtbl + 0x198);
    return e->fn(o + e->delta);
}
extern "C" void func_00240420(void *);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002FC870(void *, s32);
extern "C" void func_002403C8(void *, s32);

extern "C" void MStorage__isAvailable(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s2;
    s32 t1;
    s32 newVal;
    s32 oldVal;
    func_00240420(buf0);
    t1 = vcall_198((char *)buf0[0]);
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
    func_002403C8(buf0, 0x2);
}
