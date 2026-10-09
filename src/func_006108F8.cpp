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

extern "C" void func_00578500(s32);
extern "C" void func_00576AD8(s32, void *);
extern "C" void func_00578168(void *, s32, s32, s32, s32);

extern "C" void func_006108F8(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    func_00578500(*(s32 *)(char *)arg0);
    *(s32 *)((char *)arg0 + 0x40) = (s32)arg1;
    *(s32 *)((char *)arg0 + 0x44) = arg2;
    *(s32 *)((char *)arg0 + 0x48) = (s32)arg3;
    func_00576AD8(arg2, arg3);
    func_00578168(arg0, 0x3, 0, 0, 0);
}
