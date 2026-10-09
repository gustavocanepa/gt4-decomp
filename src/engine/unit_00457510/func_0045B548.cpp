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

extern "C" void func_0045AFC8(void *, s32);

extern "C" void func_0045B548(s32 *arg0, void *arg1) {
    s32 v_s0;
    if (*(s32 *)((char *)arg0 + 0x4) >= 0) {
        v_s0 = *(s32 *)((char *)arg1 + 0x8);
        v_s0 = (v_s0 - *(s32 *)(char *)arg1);
        *(s32 *)((char *)arg0 + 0x8) = (v_s0 - *(s32 *)((char *)arg0 + 0x4));
        *(s32 *)((char *)arg1 + 0x8) = (*(s32 *)(char *)arg1 + *(s32 *)((char *)arg0 + 0x4));
        func_0045AFC8(arg1, *(s32 *)(char *)arg0);
        func_0045AFC8(arg1, *(s32 *)((char *)arg0 + 0x8));
        *(s32 *)((char *)arg1 + 0x8) = (*(s32 *)(char *)arg1 + v_s0);
    }
}
