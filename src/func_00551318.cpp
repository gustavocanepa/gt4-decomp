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

extern char D_0086F8C0[];
extern "C" void func_00578500(s32);
extern "C" void func_00576AD8(void *, s32);
extern "C" void func_00578168(void *, s32, s32, s32, s32);

extern "C" void func_00551318(s32 *arg0, void *arg1, s32 arg2) {
    char *v_s0;
    v_s0 = (char *)&D_0086F8C0;
    func_00578500(*(s32 *)(char *)v_s0);
    *(s32 *)((char *)v_s0 + 0x40) = (s32)arg0;
    *(s32 *)((char *)v_s0 + 0x44) = (s32)arg1;
    *(s32 *)((char *)v_s0 + 0x48) = arg2;
    func_00576AD8(arg1, arg2);
    func_00578168(v_s0, 0x3, 0, 0, 0);
}
