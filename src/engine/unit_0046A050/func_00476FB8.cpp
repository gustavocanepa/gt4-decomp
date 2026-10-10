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
extern "C" s32 exception__structor_0(s32);
extern "C" s32 func_00575E60(s32, s32);

struct func_00476FB8_buf1 {
    s8 unk0;
};
struct func_00476FB8_v_s0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
    s8 unkC;
    char padD[0x3];
    s32 unk10;
};
struct func_00476FB8_v_s1 {
    char pad0[0x18];
    s32 unk18;
};
struct func_00476FB8_arg0 {
    char pad0[0x4];
    s32 unk4;
};

extern "C" void func_00476FB8(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 v_s1;
    s32 v_s0;
    s32 *p_s2;
    s32 t1;
    func_004768C0();
    *(s32 *)(char *)arg0 = 0x7;
    v_s1 = exception__structor_0(0x20);
    v_s0 = v_s1 + 0x4;
    *(s32 *)(char *)v_s1 = 0;
    ((struct func_00476FB8_buf1 *)buf1)->unk0 = (s8)0;
    p_s2 = buf1;
    ((struct func_00476FB8_v_s0 *)v_s0)->unk4 = 0;
    t1 = func_00575E60(0x10, 0x1c);
    ((struct func_00476FB8_v_s0 *)v_s0)->unk8 = 0;
    ((struct func_00476FB8_v_s0 *)v_s0)->unk4 = t1;
    ((struct func_00476FB8_v_s0 *)v_s0)->unkC = (s8)*(u8 *)(char *)p_s2;
    *(s32 *)(char *)t1 = 0;
    *(s32 *)((char *)(((struct func_00476FB8_v_s0 *)v_s0)->unk4) + 0x4) = 0;
    *(s32 *)((char *)(((struct func_00476FB8_v_s0 *)v_s0)->unk4) + 0x8) = ((struct func_00476FB8_v_s0 *)v_s0)->unk4;
    *(s32 *)((char *)(((struct func_00476FB8_v_s0 *)v_s0)->unk4) + 0xc) = ((struct func_00476FB8_v_s0 *)v_s0)->unk4;
    ((struct func_00476FB8_v_s0 *)v_s0)->unk10 = 0;
    ((struct func_00476FB8_v_s1 *)v_s1)->unk18 = 0x1;
    ((struct func_00476FB8_arg0 *)arg0)->unk4 = v_s1;
}
