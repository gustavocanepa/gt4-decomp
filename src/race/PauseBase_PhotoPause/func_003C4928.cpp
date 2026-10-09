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

extern char D_003C48D8[];
extern char D_003C4900[];
extern char D_006184D0[];
extern "C" void func_003C46C8(void);
extern "C" s32 func_003C3FA0(void *);
extern "C" void func_00372110(s32, s32);
extern "C" void func_00373CC8(s32, s32);
extern "C" s32 func_003C3F98(void *);
extern "C" void func_001074D0(void *, s32, s32, s32, s32);

extern "C" void func_003C4928(s32 *arg0) {
    s32 t1;
    s32 t2;
    func_003C46C8();
    func_00372110(func_003C3FA0(arg0), 0);
    func_00373CC8(func_003C3FA0(arg0), 0x1);
    t1 = func_003C3F98(arg0);
    *(s32 *)((char *)t1 + 0xd88) = (s32)arg0;
    *(s32 *)((char *)t1 + 0xd84) = (s32)&D_003C48D8;
    t2 = func_003C3F98(arg0);
    *(s32 *)((char *)t2 + 0xd90) = (s32)arg0;
    *(s32 *)((char *)t2 + 0xd8c) = (s32)&D_003C4900;
    func_001074D0(&D_006184D0, 0x1, 0x2, 0x280, 0x1c0);
    *(s32 *)((char *)arg0 + 0x19c) = 0x4;
}
