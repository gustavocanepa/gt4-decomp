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

extern "C" void func_0030BB18(void *);
extern "C" void func_00321EC8(void *, void *, void *);
extern "C" void func_00306E80(void *);
extern "C" s32 func_00304258(void *, void *);
extern "C" s32 func_00322060(void *);
extern "C" void func_00305DF8(s32, void *, void *);
extern "C" void func_003041B8(void *, s32);
extern "C" void func_00309378(void *, s32);

extern "C" void mImport__virtual_08(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s1;
    func_0030BB18(buf0);
    func_00321EC8(arg1, buf0, (char *)arg0 + 0x8);
    p_s1 = buf1;
    func_00306E80(p_s1);
    if (func_00304258(p_s1, buf0) != 0) {
        func_00305DF8(func_00322060(arg1), p_s1, (char *)arg0 + 0x18);
    }
    func_003041B8(p_s1, 0x2);
    func_00309378(buf0, 0x2);
}
