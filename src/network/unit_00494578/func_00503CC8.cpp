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

extern "C" void func_00576788(void);
extern "C" void func_00529650(s32, s32);
extern "C" void func_00538C68(void *);
extern "C" void func_00576100(void *);
extern "C" void func_0057B368(void *);
extern "C" void func_00576140(void *);
extern "C" void func_0057CC80(void *, void *);
extern "C" void func_0057CB00(void *, void *);
extern "C" void func_005767C0(s32);

extern "C" void func_00503CC8(s32 *arg0, void *arg1) {
    s32 buf0[4];
    char *v_s1;
    char *v_s3;
    v_s1 = (char *)arg1 + 0x38;
    v_s3 = (char *)arg1 + 0x1c;
    if (arg1 != 0) {
        buf0[0] = (s32)arg0;
        func_00576788();
        func_00529650(*(s32 *)((char *)arg1 + 0xc), *(s32 *)((char *)arg1 + 0x10));
        *(s32 *)((char *)arg1 + 0x14) = 0;
        *(s32 *)((char *)arg1 + 0x18) = 0;
        func_00538C68((char *)arg1 + 0x40);
        buf0[1] = (s32)v_s1;
        func_00576100(v_s1);
        func_0057B368(v_s3);
        func_00576140(v_s1);
        func_0057CC80((char *)arg0 + 0x3c, arg1);
        func_0057CC80((char *)arg0 + 0x48, arg1);
        func_0057CB00((char *)arg0 + 0x30, arg1);
        func_005767C0(buf0[0]);
    }
}
