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

extern "C" void func_0044A7F0(void);
extern "C" s32 func_0044A9C0(void *);
extern "C" s32 func_0044A830(void *, s32);
extern "C" s32 func_0044A898(void *, s32);
extern "C" s32 func_0044A860(void *, s32);
extern "C" s32 func_0044A8D0(void *, s32);
extern "C" void memcpy(s32, void *, s32);
extern "C" void func_0044A810(void *);

extern "C" void func_0044A908(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 v_s1;
    s32 t1;
    s32 t2;
    s32 t3;
    func_0044A7F0();
    v_s1 = func_0044A9C0(arg0);
    t1 = func_0044A830(arg0, v_s1);
    *(s32 *)(char *)t1 = (s32)arg1;
    t2 = func_0044A898(arg0, v_s1);
    *(s32 *)(char *)t2 = arg2;
    t3 = func_0044A860(arg0, v_s1);
    *(s32 *)(char *)t3 = 0x1;
    memcpy(func_0044A8D0(arg0, v_s1), arg3, *(s32 *)(char *)arg0);
    func_0044A810(arg0);
}
