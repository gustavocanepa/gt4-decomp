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

extern "C" void func_00473CC0(void *);
extern "C" void func_00472DE8(void *);
extern "C" void func_004741B0(s32, void *);
extern "C" s32 exception__structor_0(s32);
extern "C" void func_00480DB8(s32, s32);
extern "C" void func_00474F38(s32, s32, s32, s32);

extern "C" void func_00272880(s32 *arg0, void *arg1, s32 arg2) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 v_s0;
    *(s32 *)((char *)arg0 + 0xc) = (s32)arg1;
    func_00473CC0(arg1);
    func_00472DE8(buf0);
    func_004741B0(*(s32 *)((char *)arg0 + 0xc), buf0);
    *(s32 *)((char *)arg0 + 0x18) = arg2;
    if (*(s32 *)((char *)arg0 + 0x1c) != 0) {
        v_s0 = exception__structor_0(0x14);
        func_00480DB8(v_s0, 0x4000);
        *(s32 *)((char *)arg0 + 0x14) = v_s0;
        v_s0 = exception__structor_0(0x19c);
        func_00474F38(v_s0, *(s32 *)((char *)arg0 + 0xc), 0, *(s32 *)((char *)arg0 + 0x14));
        *(s32 *)((char *)arg0 + 0x10) = v_s0;
        *(s32 *)((char *)v_s0 + 0x10) = 0;
    }
}
