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

extern "C" void func_00576788(void *);
extern "C" void func_0057CC80(void *, void *);
extern "C" void func_0057CB00(void *, void *);
extern "C" void func_005767C0(void *);
extern "C" void func_00574EE8(void *);

extern "C" void func_004AD648(s32 *arg0, void *arg1) {
    char *v_s3;
    char *v_s2;
    v_s3 = (char *)arg0 + 0x10;
    v_s2 = (char *)arg1 + 0x3c;
    func_00576788(v_s3);
    func_0057CC80((char *)arg0 + 0x40, v_s2);
    func_00576788(arg1);
    *(s32 *)((char *)arg1 + 0x80) = 0x1;
    func_0057CB00((char *)arg0 + 0x4c, v_s2);
    func_005767C0(arg1);
    func_00574EE8((char *)arg0 + 0x64);
    func_005767C0(v_s3);
}
