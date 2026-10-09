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

extern "C" void func_0025B498(s32, void *, void *);
extern "C" void func_00263C40(s32);
extern "C" void func_0025B500(s32, void *, void *, void *, void *);
extern "C" void func_002D21E0(void *, f32, f32, f32);
extern "C" void func_002074E8(void *, void *);

extern "C" void func_002D3970(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 buf1[4];
    func_0025B498(*(s32 *)((char *)arg0 + 0xbc), buf0, (char *)buf0 + 0x4);
    func_00263C40(*(s32 *)((char *)arg0 + 0xc0));
    func_0025B500(*(s32 *)((char *)arg0 + 0xc0), (char *)buf0 + 0x8, (char *)buf0 + 0xc, buf1, (char *)buf1 + 0x4);
    func_002D21E0((char *)arg0 + 0xc4, *(f32 *)((char *)buf0 + 0x0), *(f32 *)((char *)buf0 + 0x8), *(f32 *)((char *)buf1 + 0x0));
    func_002D21E0((char *)arg0 + 0xfc, *(f32 *)((char *)buf0 + 0x4), *(f32 *)((char *)buf0 + 0xc), *(f32 *)((char *)buf1 + 0x4));
    func_002074E8(arg0, arg1);
}
