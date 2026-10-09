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

extern char D_0069D808[];
extern "C" s32 func_00326750(s32, s32, void *);
extern "C" void hFileIO__structor_0(s32, void *);
extern "C" void func_002FEA80(void *, void *);
extern "C" void func_002F70A0(s32, void *, s32);

extern "C" void func_002F72F0(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 v_s0;
    v_s0 = func_00326750(0xfc, 0x4, &D_0069D808);
    hFileIO__structor_0(v_s0, arg3);
    buf0[0] = v_s0;
    func_002FEA80(arg0, buf0);
    if (*(s32 *)((char *)(*(s32 *)(char *)arg1) - 0x10) != 0) {
        func_002F70A0(*(s32 *)(char *)arg0, arg1, arg2);
    }
}
