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

struct VEntry_58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(char *o) {
    VEntry_58 *e = (VEntry_58 *)((char *)((VObj_58 *)o)->vtbl + 0x58);
    return e->fn(o + e->delta);
}
extern "C" void func_002F67A0(void *);
extern "C" void func_00312370(void *, void *);
extern "C" void func_00309360(void *, void *);
extern "C" s32 func_00314920(s32);
extern "C" s32 func_002F70A0(s32, s32, s32);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002FC870(void *, s32);
extern "C" void func_00309378(void *, s32);
extern "C" void func_00312318(void *, s32);
extern "C" void func_002F6748(void *, s32);

extern "C" void func_002F68E8(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    s32 *p_s4;
    s32 *p_s3;
    s32 v_s1;
    s32 v_s0;
    s32 *p_s1;
    s32 t1;
    s32 newVal;
    s32 oldVal;
    if (arg2 == 0x2) {
        func_002F67A0(buf0);
        p_s4 = buf1;
        func_00312370(p_s4, arg3);
        p_s3 = buf2;
        func_00309360(p_s3, (char *)arg3 + 0x4);
        v_s1 = buf0[0];
        v_s0 = func_00314920(*p_s4);
        t1 = func_002F70A0(v_s1, v_s0, vcall_58((char *)(*p_s3)));
        p_s1 = buf3;
        func_002FE278(p_s1, t1 != 0);
        if (arg0 != p_s1) {
            newVal = *p_s1;
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_002FC870(p_s1, 0x2);
        func_00309378(p_s3, 0x2);
        func_00312318(p_s4, 0x2);
        func_002F6748(buf0, 0x2);
    } else {
        func_002FE278(buf0, 0);
        if (arg0 != buf0) {
            newVal = buf0[0];
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_002FC870(buf0, 0x2);
    }
}
