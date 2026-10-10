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
extern "C" void func_005EAF80(void *, void *, s32);
extern "C" void func_00306E80(void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_005767C0(void *);
extern "C" void func_003041A0(void *, void *);
extern "C" void func_003041B8(void *, s32);

struct func_002EAC30_v_s0 {
    u8 pad0[0x4];
    s32 unk4;
};

extern "C" void * func_002EAC30(s32 *arg0, void *arg1, s32 arg2) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    char *v_s2;
    char *v_s0;
    s32 *p_s1;
    s32 v_s0_s32;
    v_s2 = (char *)arg1 + 0x44;
    v_s0 = (char *)arg1 + 0x28;
    func_00576788(v_s2);
    func_005EAF80(buf0, v_s0, arg2);
    p_s1 = buf1;
    func_00306E80(p_s1);
    buf2[0] = ((struct func_002EAC30_v_s0 *)v_s0)->unk4;
    if (buf0[0] != ((struct func_002EAC30_v_s0 *)v_s0)->unk4) {
        if ((char *)p_s1 != (char *)(buf0[0] + 0x14)) {
            v_s0_s32 = *(s32 *)(char *)(buf0[0] + 0x14);
            if (v_s0_s32 != 0) {
                func_003285A8(v_s0_s32);
            }
            if (*p_s1 != 0) {
                func_003285F8(*p_s1);
            }
            *p_s1 = v_s0_s32;
        }
    }
    func_005767C0(v_s2);
    func_003041A0(arg0, p_s1);
    func_003041B8(p_s1, 0x2);
    return arg0;
}
