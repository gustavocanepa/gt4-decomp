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

extern "C" void func_003923A0(void *);
extern "C" s32 func_00445518(void *);
extern "C" s32 func_00445548(void *);
extern "C" void func_003923D0(void *, s32, s32);

extern "C" void func_003B5D90(s32 *arg0) {
    char *v_s3;
    char *v_s2;
    s32 v_s0;
    v_s3 = (char *)arg0 + 0x2900;
    v_s2 = (char *)arg0 + 0x20;
    func_003923A0(v_s3);
    if (*(s32 *)((char *)arg0 + 0x28fc) == 0) {
        v_s0 = func_00445518(v_s2);
        func_003923D0(v_s3, v_s0, func_00445548(v_s2));
        *(s32 *)((char *)arg0 + 0x28fc) = 0x1;
    }
}
