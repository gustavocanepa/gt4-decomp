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

extern "C" void func_00480EA0(s32);
extern "C" void strobe__ActionInstance__doAction(void *, void *, s32, s32, void *, void *, void *);
extern "C" void func_00575DA0(s32);

struct func_004817E8_arg3 {
    char pad0[0x164];
    s32 unk164;
};
struct func_004817E8_arg2 {
    char pad0[0x4];
    s32 unk4;
};

extern "C" void * func_004817E8(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    buf0[1] = 0;
    buf0[2] = 0;
    buf0[3] = 0;
    buf1[0] = 0;
    func_00480EA0(((struct func_004817E8_arg3 *)arg3)->unk164);
    strobe__ActionInstance__doAction(arg0, arg1, *(s32 *)(char *)arg2, ((struct func_004817E8_arg2 *)arg2)->unk4, buf0, arg1, arg3);
    buf3[0] = buf0[1];
    if (buf0[1] != 0) {
        func_00575DA0(buf0[1]);
    }
    return arg0;
}
