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

struct VEntry_28 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_28 { char pad0[4]; VEntry_28 *vtbl; };
static inline s32 vcall_28(char *o) {
    VEntry_28 *e = (VEntry_28 *)((char *)((VObj_28 *)o)->vtbl + 0x28);
    return e->fn(o + e->delta);
}
extern "C" void func_002FE278(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002FC870(void *, s32);

extern "C" void func_00309480(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 newVal;
    s32 oldVal;
    func_002FE278(buf0, vcall_28((char *)*(s32 *)arg1));
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
}
