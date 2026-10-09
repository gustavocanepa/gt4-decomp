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

extern "C" void func_004768C0(void);
extern "C" s32 func_005C1498(s32);
extern "C" s32 func_00575E60(s32, s32);

extern "C" void func_00476FB8(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 v_s1;
    s32 v_s0;
    s32 *p_s2;
    s32 t1;
    func_004768C0();
    *(s32 *)(char *)arg0 = 0x7;
    v_s1 = func_005C1498(0x20);
    v_s0 = v_s1 + 0x4;
    *(s32 *)(char *)v_s1 = 0;
    *(s8 *)((char *)buf1 + 0x0) = (s8)0;
    p_s2 = buf1;
    *(s32 *)((char *)v_s0 + 0x4) = 0;
    t1 = func_00575E60(0x10, 0x1c);
    *(s32 *)((char *)v_s0 + 0x8) = 0;
    *(s32 *)((char *)v_s0 + 0x4) = t1;
    *(s8 *)((char *)v_s0 + 0xc) = (s8)*(u8 *)(char *)p_s2;
    *(s32 *)(char *)t1 = 0;
    *(s32 *)((char *)(*(s32 *)((char *)v_s0 + 0x4)) + 0x4) = 0;
    *(s32 *)((char *)(*(s32 *)((char *)v_s0 + 0x4)) + 0x8) = *(s32 *)((char *)v_s0 + 0x4);
    *(s32 *)((char *)(*(s32 *)((char *)v_s0 + 0x4)) + 0xc) = *(s32 *)((char *)v_s0 + 0x4);
    *(s32 *)((char *)v_s0 + 0x10) = 0;
    *(s32 *)((char *)v_s1 + 0x18) = 0x1;
    *(s32 *)((char *)arg0 + 0x4) = v_s1;
}
