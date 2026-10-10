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
extern "C" void * func_00192A58(void *);
extern "C" void * func_002FE278(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002FC870(void *, s32);
extern "C" void func_00192A00(void *, s32);

struct func_00196160_v_s0 {
    char pad0[0x128];
    s32 unk128;
};

extern "C" void MPhotoMapWindow__get_brightness(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s2;
    s32 newVal;
    s32 oldVal;
    s32 v_s0;
    s32 t1;
    if (arg2 == 0) {
        func_00192A58(buf0);
        p_s2 = buf1;
        func_002FE278(p_s2, *(s32 *)((char *)buf0[0] + 0x128));
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
        func_002FC870(p_s2, 0x2);
        func_00192A00(buf0, 0x2);
    } else {
        if (arg2 == 1) {
            func_00192A58(buf0);
            v_s0 = buf0[0];
            t1 = vcall_58((char *)(*(s32 *)(char *)arg3));
            ((struct func_00196160_v_s0 *)v_s0)->unk128 = t1;
            func_00192A00(buf0, 0x2);
        }
    }
}
