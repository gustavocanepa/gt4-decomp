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

extern "C" void func_00289700(void *);
extern "C" void func_002F7BC0(void *, void *);
extern "C" f32 func_002F9158(s32);
extern "C" void func_0028A968(s32, f32);
extern "C" void func_002F7B68(void *, s32);
extern "C" void func_002896A8(void *, s32);
extern "C" f32 func_0028A938(s32);
extern "C" void func_002F9360(void *, f32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);

extern "C" void MCrossTransition__get_period(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 *p_s1;
    s32 v_s0;
    s32 *p_s2;
    f32 t1;
    s32 newVal;
    s32 oldVal;
    if (arg2 > 0) {
        func_00289700(buf0);
        p_s1 = buf1;
        func_002F7BC0(p_s1, arg3);
        v_s0 = buf0[0];
        func_0028A968(v_s0, func_002F9158(*p_s1));
        func_002F7B68(p_s1, 0x2);
        func_002896A8(buf0, 0x2);
    } else {
        func_00289700(buf0);
        t1 = func_0028A938(buf0[0]);
        p_s2 = buf2;
        func_002F9360(p_s2, t1);
        if (arg0 != p_s2) {
            newVal = *p_s2;
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_002F7B68(p_s2, 0x2);
        func_002896A8(buf0, 0x2);
    }
}
