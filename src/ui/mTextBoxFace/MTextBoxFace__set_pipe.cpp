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

extern "C" void func_002E4BD8(void *);
extern "C" void func_00227180(void *, void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_00227128(void *, s32);
extern "C" void func_002E4B80(void *, s32);

extern "C" void MTextBoxFace__set_pipe(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s2;
    s32 v_s1;
    s32 v_s0;
    if (arg2 > 0) {
        func_002E4BD8(buf0);
        p_s2 = buf1;
        v_s1 = buf0[0] + 0xbc;
        func_00227180(p_s2, arg3);
        if ((char *)v_s1 != (char *)p_s2) {
            v_s0 = *p_s2;
            if (v_s0 != 0) {
                func_003285A8(v_s0);
            }
            if (*(s32 *)(char *)v_s1 != 0) {
                func_003285F8(*(s32 *)(char *)v_s1);
            }
            *(s32 *)(char *)v_s1 = v_s0;
        }
        func_00227128(p_s2, 0x2);
        func_002E4B80(buf0, 0x2);
    }
}
