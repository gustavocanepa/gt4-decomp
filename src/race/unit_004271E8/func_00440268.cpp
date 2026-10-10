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

extern "C" void func_0043FE58(void *, s32);
extern "C" s32 func_004452A8(void *, s32, u8, u8);

struct func_00440268_arg0 {
    char pad0[0x490];
    s32 unk490;
};
struct func_00440268_v_s0 {
    char pad0[0x28];
    s64 unk28;
    char pad30[0xFF];
    s8 unk12F;
    s8 unk130;
};
struct func_00440268_arg2 {
    char pad0[0x3];
    u8 unk3;
    char pad4[0x2];
    u8 unk6;
    u8 unk7;
    char pad8[0x2];
    u8 unkA;
};

extern "C" void func_00440268(s32 *arg0, void *arg1, s32 arg2) {
    char *v_s0;
    s32 t1;
    s32 t2;
    v_s0 = (char *)arg0 + (((((((struct func_00440268_arg0 *)arg0)->unk490 << 1) + ((struct func_00440268_arg0 *)arg0)->unk490) << 4) - ((struct func_00440268_arg0 *)arg0)->unk490) << 3);
    v_s0 = (char *)v_s0 + 0x8;
    ((struct func_00440268_v_s0 *)v_s0)->unk28 = (s64)arg1;
    func_0043FE58(arg0, arg2);
    t1 = func_004452A8(v_s0, 0x1, ((struct func_00440268_arg2 *)arg2)->unk6, ((struct func_00440268_arg2 *)arg2)->unk3);
    ((struct func_00440268_v_s0 *)v_s0)->unk12F = (s8)t1;
    t2 = func_004452A8(v_s0, 0x1, ((struct func_00440268_arg2 *)arg2)->unkA, ((struct func_00440268_arg2 *)arg2)->unk7);
    ((struct func_00440268_v_s0 *)v_s0)->unk130 = (s8)t2;
}
