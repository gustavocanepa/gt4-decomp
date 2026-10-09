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

extern char IfWidget__vtable[];
extern "C" void func_00250BF8(void *, void *);
extern "C" void func_0024B218(void *, void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_0024B248(void *, s32);
extern "C" void func_005DD9C0(void *);

extern "C" void IfWidget__structor_0(s32 *arg0, void *arg1) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    char *v_s1;
    s32 *p_s3;
    s32 v_s0;
    v_s1 = (char *)arg0 + 0x68;
    buf0[0] = (s32)&IfWidget__vtable;
    buf0[1] = (s32)arg0;
    func_00250BF8(arg1, buf0);
    p_s3 = buf1;
    buf2[0] = 0;
    func_0024B218(p_s3, buf2);
    if ((char *)v_s1 != (char *)p_s3) {
        v_s0 = *p_s3;
        if (v_s0 != 0) {
            func_003285A8(v_s0);
        }
        if (*(s32 *)(char *)v_s1 != 0) {
            func_003285F8(*(s32 *)(char *)v_s1);
        }
        *(s32 *)(char *)v_s1 = v_s0;
    }
    func_0024B248(p_s3, 0x2);
    func_005DD9C0((char *)arg0 + 0x60);
}
