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

extern char D_005A3628[];
extern "C" void func_005A3458(void *, s32, s32, void *);

extern "C" void func_005A3668(s32 *arg0) {
    char *v_s1;
    v_s1 = (char *)arg0 + 0x1e4;
    *(s32 *)((char *)arg0 + 0x3c) = (s32)&D_005A3628;
    *(s32 *)((char *)arg0 + 0x38) = 0x1;
    func_005A3458(v_s1, 0x4, 0, arg0);
    func_005A3458((char *)arg0 + 0x23c, 0x9, 0x1, arg0);
    func_005A3458((char *)arg0 + 0x294, 0xa, 0x2, arg0);
    *(s32 *)((char *)arg0 + 0x1d8) = 0;
    *(s32 *)((char *)arg0 + 0x1e0) = (s32)v_s1;
    *(s32 *)((char *)arg0 + 0x1dc) = 0x3;
}
