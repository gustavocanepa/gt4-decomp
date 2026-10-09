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

extern char D_0061850C[];
extern "C" void func_004A3078(s32);
extern "C" void func_004A2980(s32);
extern "C" void func_001056A0(void *);
extern "C" void func_004A3230(s32);

extern "C" void func_00330CA8(s32 *arg0) {
    char *v_s0;
    s32 v_s1;
    v_s0 = (char *)&D_0061850C;
    func_004A3078(0);
    v_s1 = 0x1;
    func_004A2980(-0x1);
    func_001056A0((char *)v_s0 + (((*(s32 *)((char *)v_s0 + 0x78) << 4) - *(s32 *)((char *)v_s0 + 0x78)) << 2));
    func_004A3230(0x1);
    func_001056A0((char *)v_s0 + ((((v_s1 - *(s32 *)((char *)v_s0 + 0x78)) << 4) - (v_s1 - *(s32 *)((char *)v_s0 + 0x78))) << 2));
    func_004A3230(0x1);
    *(s32 *)((char *)v_s0 + (((*(s32 *)((char *)v_s0 + 0x78) << 4) - *(s32 *)((char *)v_s0 + 0x78)) << 2) + 0x30) = 0;
    v_s1 = (v_s1 - *(s32 *)((char *)v_s0 + 0x78));
    *(s32 *)((char *)v_s0 + (((v_s1 << 4) - v_s1) << 2) + 0x30) = 0;
}
