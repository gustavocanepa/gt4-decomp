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

extern char D_0055CF28[];
extern char D_00655340[];
extern "C" void func_00576100(void *);
extern "C" void func_0055CFE8(void *, s64);
extern "C" void func_0055C9A0(s32, void *, void *, void *, s32);
extern "C" void func_00576140(void *);

extern "C" void func_0055B250(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    char *v_s2;
    v_s2 = (char *)&D_00655340;
    func_00576100(v_s2);
    if (*(s32 *)((char *)arg0 + 0x60) != 0) {
        func_0055CFE8(buf0, *(s64 *)((char *)arg0 + 0x28));
        func_0055C9A0(buf0[0], buf0, &D_0055CF28, arg1, 0);
        *(s32 *)((char *)arg0 + 0x60) = 0x3;
    }
    func_00576140(v_s2);
}
