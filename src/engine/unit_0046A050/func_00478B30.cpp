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

extern "C" s32 func_0047E658(void *, void *);
extern "C" void func_00473380(s32, s32);
extern "C" void func_004A1638(s32);
extern "C" void func_004AB040(s32);
extern "C" void func_00473750(s32, void *);
extern "C" void func_004A5348(s32);
extern "C" void func_004A74B4(s32);

extern "C" void func_00478B30(s32 *arg0, void *arg1, s32 arg2) {
    s32 buf0[4];
    s32 v_s0;
    if (*(s32 *)((char *)arg0 + 0x6e38) == 0) {
        buf0[0] = 0x80ffffff;
        func_00473380(*(s32 *)((char *)arg0 + 0x6e14), func_0047E658((char *)arg0 + 0x6e18, buf0));
    }
    v_s0 = *(s32 *)((char *)arg0 + 0x6e14);
    func_004A1638(0x2);
    func_004AB040(0x9);
    *(s32 *)((char *)v_s0 + 0x4) = 0x1;
    if (arg1 != 0) {
        func_00473750(*(s32 *)((char *)arg0 + 0x6e14), arg1);
    }
    func_004A5348(0x2);
    func_004A74B4(arg2);
    func_004A5348(0);
}
