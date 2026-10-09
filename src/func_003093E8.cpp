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

struct VEntry_50 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_50 { char pad0[4]; VEntry_50 *vtbl; };
static inline s32 vcall_50(char *o) {
    VEntry_50 *e = (VEntry_50 *)((char *)((VObj_50 *)o)->vtbl + 0x50);
    return e->fn(o + e->delta);
}
extern "C" void func_002F29D8(void *, void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002F2A08(void *, s32);

extern "C" void func_003093E8(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s0;
    s32 t1;
    s32 newVal;
    s32 oldVal;
    p_s0 = buf1;
    t1 = vcall_50((char *)(*(s32 *)(char *)arg1));
    buf1[0] = t1;
    func_002F29D8(buf0, p_s0);
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
    func_002F2A08(buf0, 0x2);
}
