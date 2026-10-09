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

extern char D_0083EF28[];
extern "C" void func_002ECDE0(void *);
extern "C" void func_002EC260(void *, s32, void *);
extern "C" void func_00305DF8(void *, void *, void *);
extern "C" void func_003041B8(void *, s32);
extern "C" void func_002EA590(void *, s32);

extern "C" void func_00305D78(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s0;
    func_002ECDE0(buf0);
    p_s0 = buf1;
    func_002EC260(p_s0, buf0[0], arg1);
    func_00305DF8(arg0, p_s0, &D_0083EF28);
    func_003041B8(p_s0, 0x2);
    func_002EA590(buf0, 0x2);
}
