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

extern "C" void func_002CE540(void *);
extern "C" void func_0022AD20(void *, void *);
extern "C" void func_002F9B90(void *, void *);
extern "C" void func_002CEB20(s32, void *);
extern "C" void func_002F9B38(void *, s32);
extern "C" void func_0022ACC8(void *, s32);
extern "C" void func_002CE4E8(void *, s32);

extern "C" void func_002CE738(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 *p_s1;
    s32 *p_s0;
    if (arg2 >= 0x2) {
        func_002CE540(buf0);
        p_s1 = buf1;
        func_0022AD20(p_s1, arg3);
        p_s0 = buf2;
        *(s32 *)((char *)buf0[0] + 0x1c) = *p_s1;
        func_002F9B90(p_s0, (char *)arg3 + 0x4);
        func_002CEB20(buf0[0], p_s0);
        func_002F9B38(p_s0, 0x2);
        func_0022ACC8(p_s1, 0x2);
        func_002CE4E8(buf0, 0x2);
    }
}
