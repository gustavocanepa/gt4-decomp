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

extern "C" void func_004F0A20(void *, s32);
extern "C" s32 func_0052EE68(s32, s32);
extern "C" void func_004F8820(void *, s32);
extern "C" s32 func_004F0D48(void *);
extern "C" void func_004F0A90(void *);
extern "C" void func_004F8D00(void *);
extern "C" void func_0052F0D0(s32, s32);
extern "C" void func_004FB480(void *, s32);

extern "C" void func_004F6630(s32 *arg0) {
    s32 v_s2;
    s32 v_s1;
    v_s2 = 0x1;
    func_004F0A20(arg0, 0);
    *(s32 *)((char *)(*(s32 *)((char *)arg0 + 0x5a8)) + 0x5b30) = 0;
    *(s32 *)((char *)(*(s32 *)((char *)arg0 + 0x5a8)) + 0x5b34) = 0;
    func_004F8820(arg0, func_0052EE68(*(s32 *)((char *)arg0 + 0x5a8), *(s32 *)((char *)arg0 + 0x5a8) + 0x1d8));
    if (func_004F0D48(arg0) == v_s2) {
        func_004F0A90(arg0);
    }
    v_s1 = func_004F0D48(arg0);
    if (v_s1 == v_s2) {
        *(s32 *)((char *)arg0 + 0x2228) = *(s32 *)((char *)(*(s32 *)((char *)arg0 + 0x5a8)) + 0x1e0);
        func_004F8D00(arg0);
        func_0052F0D0(*(s32 *)((char *)arg0 + 0x2228), 0x1);
        func_004FB480(arg0, *(s32 *)((char *)arg0 + 0xa3c));
        *(s32 *)((char *)arg0 + 0x5e4) = v_s1;
        *(s32 *)((char *)arg0 + 0xa34) = 0;
    }
}
