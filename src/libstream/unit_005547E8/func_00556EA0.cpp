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

extern char D_0064D218[];
extern char D_0064D248[];
extern char D_00655290[];
extern "C" void func_00567018(void *, s32, void *, s32, s32);
extern "C" void func_005A48D8(void *, s32, s32);

extern "C" void func_00556EA0(s32 *arg0) {
    char *v_s2;
    char *v_s1;
    v_s2 = (char *)arg0 + 0x4;
    v_s1 = (char *)&D_00655290;
    *(s32 *)((char *)arg0 + 0x280) = 0;
    func_00567018(v_s1, *(s32 *)(char *)arg0, &D_0064D248, 0x3, 0x1);
    func_005A48D8(v_s2, 0, 0x40);
    *(s32 *)((char *)arg0 + 0x44) = (s32)v_s2;
    func_00567018(v_s1, *(s32 *)(char *)arg0, &D_0064D218, 0x25, 0x1);
}
