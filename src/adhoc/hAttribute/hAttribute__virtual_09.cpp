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
extern "C" void func_002F3508(s32);
extern "C" void func_0030B678(s32, s32, s32);

struct hAttribute__virtual_09_arg0 {
    u8 pad0[0xC];
    s32 unkC;
};

extern "C" void hAttribute__virtual_09(s32 *arg0, void *arg1, s32 arg2) {
    if (((struct hAttribute__virtual_09_arg0 *)arg0)->unkC == -0x1) {
        func_002F3508(vcall_50((char *)(*(s32 *)(char *)arg1)));
    }
    func_0030B678(*(s32 *)(char *)arg1, ((struct hAttribute__virtual_09_arg0 *)arg0)->unkC, arg2);
}
