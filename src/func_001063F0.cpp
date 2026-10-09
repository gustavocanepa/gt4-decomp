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

extern "C" void func_004AA478(void);
extern "C" s32 func_004AA570(s32, s32);
extern "C" void func_001053F8(void *, s32);
extern "C" void func_00105460(void *, s32, s32);
extern "C" void func_001054A0(void *, s32);

extern "C" void func_001063F0(s32 *arg0) {
    char *v_s0;
    char *v_s1;
    s32 v_s2;
    char *v_s4;
    s32 v_s6;
    s32 v_s3;
    s32 v_s7;
    v_s0 = (char *)arg0 + 0x3c;
    v_s1 = (char *)arg0 + 0xb8;
    v_s2 = 0x1;
    v_s4 = (char *)arg0 + 0x134;
    v_s6 = 0x31;
    func_004AA478();
    *(s32 *)((char *)v_s0 + 0x78) = 0;
    v_s3 = func_004AA570(0x69000, 0);
    *(s32 *)((char *)arg0 + 0x170) = v_s3;
    v_s7 = 0x23000;
    v_s7 = (v_s7 + v_s3);
    func_001053F8((char *)v_s0 + (((*(s32 *)((char *)v_s0 + 0x78) << 4) - *(s32 *)((char *)v_s0 + 0x78)) << 2), v_s3);
    *(s32 *)((char *)v_s0 + (((*(s32 *)((char *)v_s0 + 0x78) << 4) - *(s32 *)((char *)v_s0 + 0x78)) << 2) + 0x4) = v_s2;
    func_00105460((char *)v_s0 + (((*(s32 *)((char *)v_s0 + 0x78) << 4) - *(s32 *)((char *)v_s0 + 0x78)) << 2), 0x280, 0xe0);
    func_001054A0((char *)v_s0 + (((*(s32 *)((char *)v_s0 + 0x78) << 4) - *(s32 *)((char *)v_s0 + 0x78)) << 2), 0x1);
    *(s32 *)((char *)v_s0 + (((*(s32 *)((char *)v_s0 + 0x78) << 4) - *(s32 *)((char *)v_s0 + 0x78)) << 2) + 0x2c) = 0;
    func_001053F8((char *)v_s0 + ((((v_s2 - *(s32 *)((char *)v_s0 + 0x78)) << 4) - (v_s2 - *(s32 *)((char *)v_s0 + 0x78))) << 2), (0x46000 + v_s3));
    *(s32 *)((char *)v_s0 + ((((v_s2 - *(s32 *)((char *)v_s0 + 0x78)) << 4) - (v_s2 - *(s32 *)((char *)v_s0 + 0x78))) << 2) + 0x4) = v_s2;
    func_00105460((char *)v_s0 + ((((v_s2 - *(s32 *)((char *)v_s0 + 0x78)) << 4) - (v_s2 - *(s32 *)((char *)v_s0 + 0x78))) << 2), 0x280, 0xe0);
    func_001054A0((char *)v_s0 + ((((v_s2 - *(s32 *)((char *)v_s0 + 0x78)) << 4) - (v_s2 - *(s32 *)((char *)v_s0 + 0x78))) << 2), 0x1);
    v_s0 = (char *)v_s0 + ((((v_s2 - *(s32 *)((char *)v_s0 + 0x78)) << 4) - (v_s2 - *(s32 *)((char *)v_s0 + 0x78))) << 2);
    *(s32 *)((char *)v_s0 + 0x2c) = 0;
    func_001053F8((char *)v_s1 + (((*(s32 *)((char *)v_s1 + 0x78) << 4) - *(s32 *)((char *)v_s1 + 0x78)) << 2), v_s3);
    *(s32 *)((char *)v_s1 + (((*(s32 *)((char *)v_s1 + 0x78) << 4) - *(s32 *)((char *)v_s1 + 0x78)) << 2) + 0x4) = v_s6;
    func_00105460((char *)v_s1 + (((*(s32 *)((char *)v_s1 + 0x78) << 4) - *(s32 *)((char *)v_s1 + 0x78)) << 2), 0x280, 0x1c0);
    func_001054A0((char *)v_s1 + (((*(s32 *)((char *)v_s1 + 0x78) << 4) - *(s32 *)((char *)v_s1 + 0x78)) << 2), 0x9);
    *(s32 *)((char *)v_s1 + (((*(s32 *)((char *)v_s1 + 0x78) << 4) - *(s32 *)((char *)v_s1 + 0x78)) << 2) + 0x2c) = 0;
    func_001053F8((char *)v_s1 + ((((v_s2 - *(s32 *)((char *)v_s1 + 0x78)) << 4) - (v_s2 - *(s32 *)((char *)v_s1 + 0x78))) << 2), v_s7);
    *(s32 *)((char *)v_s1 + ((((v_s2 - *(s32 *)((char *)v_s1 + 0x78)) << 4) - (v_s2 - *(s32 *)((char *)v_s1 + 0x78))) << 2) + 0x4) = v_s6;
    func_00105460((char *)v_s1 + ((((v_s2 - *(s32 *)((char *)v_s1 + 0x78)) << 4) - (v_s2 - *(s32 *)((char *)v_s1 + 0x78))) << 2), 0x280, 0x1c0);
    func_001054A0((char *)v_s1 + ((((v_s2 - *(s32 *)((char *)v_s1 + 0x78)) << 4) - (v_s2 - *(s32 *)((char *)v_s1 + 0x78))) << 2), 0x9);
    v_s1 = (char *)v_s1 + ((((v_s2 - *(s32 *)((char *)v_s1 + 0x78)) << 4) - (v_s2 - *(s32 *)((char *)v_s1 + 0x78))) << 2);
    *(s32 *)((char *)v_s1 + 0x2c) = 0;
    func_001053F8(v_s4, v_s7);
    *(s32 *)((char *)v_s4 + 0x4) = v_s6;
    func_00105460(v_s4, 0x280, 0xe0);
    func_001054A0(v_s4, 0x1);
    *(s32 *)((char *)v_s4 + 0x2c) = 0;
    *(s32 *)((char *)arg0 + 0x2c) = v_s2;
}
