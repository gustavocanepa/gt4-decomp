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
extern "C" void func_00192A58(void *);
extern "C" void func_0022AD20(void *, void *);
extern "C" f32 func_00195270(s32, s32, s32);
extern "C" void func_002F9360(void *, f32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002F7B68(void *, s32);
extern "C" void func_0022ACC8(void *, s32);
extern "C" void func_00192A00(void *, s32);

struct MPhotoMapWindow__getAperture_arg3 {
    char pad0[0x4];
    s32 unk4;
};

extern "C" void MPhotoMapWindow__getAperture(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 *p_s3;
    s32 v_s1;
    s32 v_s0;
    s32 *p_s1;
    f32 t1;
    s32 newVal;
    s32 oldVal;
    if (arg2 == 0x2) {
        func_00192A58(buf0);
        p_s3 = buf1;
        func_0022AD20(p_s3, arg3);
        v_s1 = *p_s3;
        v_s0 = buf0[0];
        t1 = func_00195270(v_s0, v_s1, vcall_58((char *)(((struct MPhotoMapWindow__getAperture_arg3 *)arg3)->unk4)));
        p_s1 = buf2;
        func_002F9360(p_s1, t1);
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
        func_002F7B68(p_s1, 0x2);
        func_0022ACC8(p_s3, 0x2);
        func_00192A00(buf0, 0x2);
    }
}
