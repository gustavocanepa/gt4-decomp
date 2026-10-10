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

struct VEntry_60 { s16 delta; s16 index; f32 (*fn)(void *); };
struct VObj_60 { char pad0[4]; VEntry_60 *vtbl; };
static inline f32 vcall_60(char *o) {
    VEntry_60 *e = (VEntry_60 *)((char *)((VObj_60 *)o)->vtbl + 0x60);
    return e->fn(o + e->delta);
}
extern "C" void func_002F9360(void *, f32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002F7B68(void *, s32);

struct func_002F7E78_arg0 {
    char pad0[0x10];
    f32 unk10;
};

extern "C" void hFloat__virtual_23(s32 *arg0, void *arg1, s32 arg2, char **arg3, s32 *arg4) {
    s32 buf0[4];
    s32 newVal;
    s32 oldVal;
    func_002F9360(buf0, (((struct func_002F7E78_arg0 *)arg0)->unk10 * vcall_60((char *)(*(s32 *)(char *)arg4))));
    if (arg1 != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *(s32 *)arg1;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *(s32 *)arg1 = newVal;
    }
    func_002F7B68(buf0, 0x2);
}
