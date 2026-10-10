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

extern char D_0068FD80[];
extern "C" void func_00575DA0(s32);
extern "C" void func_005A609C(void *, void *);
extern "C" void func_005A5DC8(void *, void *);
extern "C" void func_004AE230(void *, void *, s32);
extern "C" void func_00458238(s32);

struct func_001553C0_arg0 {
    char pad0[0x89C];
    s32 unk89C;
};

extern "C" void func_001553C0(s32 *arg0, void *arg1, s32 arg2) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    s32 buf4[4];
    s32 buf5[4];
    s32 buf6[4];
    s32 buf7[4];
    s32 buf8[4];
    s32 buf9[4];
    s32 buf10[4];
    func_00575DA0(((struct func_001553C0_arg0 *)arg0)->unk89C);
    ((struct func_001553C0_arg0 *)arg0)->unk89C = 0;
    if (arg2 != 0) {
        func_005A609C(buf0, arg1);
        func_005A5DC8(buf0, &D_0068FD80);
        func_004AE230(buf9, buf0, 0x1);
        ((struct func_001553C0_arg0 *)arg0)->unk89C = buf10[0];
        func_00458238(buf10[0]);
    }
}
