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

extern char D_0069CF88[];
extern "C" void func_0023FB80(void *);
extern "C" void func_0023F8C8(s32, void *);
extern "C" void func_0023DDF0(void *, s32);
extern "C" void func_0057CE40(void *, s32);
extern "C" void func_002DF3A0(void *, void *, s32);
extern "C" void func_002306D0(void *, s32);
extern "C" void func_00231F60(void *, s32);

extern "C" void func_002DF7B0(s32 *arg0, void *arg1, s32 arg2) {
    s32 buf0[4];
    func_0023FB80(buf0);
    func_0023F8C8(buf0[0], &D_0069CF88);
    func_0023DDF0(buf0, 0x2);
    if (arg2 != 0) {
        func_0057CE40((char *)arg0 + 0xcc, *(s32 *)((char *)arg0 + 0xf8));
        func_002DF3A0(arg0, arg1, 0);
    }
    *(s32 *)((char *)arg0 + 0x10c) = 0;
    func_002306D0(arg1, 0x1);
    func_00231F60(arg1, 0);
}
