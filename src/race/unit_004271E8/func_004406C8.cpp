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

extern "C" void func_00440030(void *, s32);
extern "C" s32 func_004452A8(void *, u8, u8, u8);

struct func_004406C8_arg0 {
    char pad0[0x490];
    s32 unk490;
};
struct func_004406C8_v_s1 {
    char pad0[0x58];
    s64 unk58;
    char pad60[0xF0];
    s8 unk150;
    s8 unk151;
    s8 unk152;
    s8 unk153;
    s8 unk154;
    s8 unk155;
};
struct func_004406C8_arg2 {
    char pad0[0xF8];
    u8 unkF8;
    u8 unkF9;
    u8 unkFA;
    char padFB[0x1];
    u8 unkFC;
    u8 unkFD;
    u8 unkFE;
    char padFF[0x1];
    u8 unk100;
    u8 unk101;
    u8 unk102;
    char pad103[0x1];
    u8 unk104;
    u8 unk105;
    u8 unk106;
    char pad107[0x1];
    u8 unk108;
    u8 unk109;
    u8 unk10A;
    char pad10B[0x1];
    u8 unk10C;
    u8 unk10D;
    u8 unk10E;
};

extern "C" void func_004406C8(s32 *arg0, void *arg1, s32 arg2) {
    char *v_s1;
    s32 t1;
    s32 t2;
    s32 t3;
    s32 t4;
    s32 t5;
    s32 t6;
    v_s1 = (char *)arg0 + (((((((struct func_004406C8_arg0 *)arg0)->unk490 << 1) + ((struct func_004406C8_arg0 *)arg0)->unk490) << 4) - ((struct func_004406C8_arg0 *)arg0)->unk490) << 3);
    v_s1 = (char *)v_s1 + 0x8;
    ((struct func_004406C8_v_s1 *)v_s1)->unk58 = (s64)arg1;
    func_00440030(arg0, arg2);
    t1 = func_004452A8(v_s1, ((struct func_004406C8_arg2 *)arg2)->unkF8, ((struct func_004406C8_arg2 *)arg2)->unkFA, ((struct func_004406C8_arg2 *)arg2)->unkF9);
    ((struct func_004406C8_v_s1 *)v_s1)->unk150 = (s8)t1;
    t2 = func_004452A8(v_s1, ((struct func_004406C8_arg2 *)arg2)->unk104, ((struct func_004406C8_arg2 *)arg2)->unk106, ((struct func_004406C8_arg2 *)arg2)->unk105);
    ((struct func_004406C8_v_s1 *)v_s1)->unk151 = (s8)t2;
    t3 = func_004452A8(v_s1, ((struct func_004406C8_arg2 *)arg2)->unkFC, ((struct func_004406C8_arg2 *)arg2)->unkFE, ((struct func_004406C8_arg2 *)arg2)->unkFD);
    ((struct func_004406C8_v_s1 *)v_s1)->unk152 = (s8)t3;
    t4 = func_004452A8(v_s1, ((struct func_004406C8_arg2 *)arg2)->unk108, ((struct func_004406C8_arg2 *)arg2)->unk10A, ((struct func_004406C8_arg2 *)arg2)->unk109);
    ((struct func_004406C8_v_s1 *)v_s1)->unk153 = (s8)t4;
    t5 = func_004452A8(v_s1, ((struct func_004406C8_arg2 *)arg2)->unk100, ((struct func_004406C8_arg2 *)arg2)->unk102, ((struct func_004406C8_arg2 *)arg2)->unk101);
    ((struct func_004406C8_v_s1 *)v_s1)->unk154 = (s8)t5;
    t6 = func_004452A8(v_s1, ((struct func_004406C8_arg2 *)arg2)->unk10C, ((struct func_004406C8_arg2 *)arg2)->unk10E, ((struct func_004406C8_arg2 *)arg2)->unk10D);
    ((struct func_004406C8_v_s1 *)v_s1)->unk155 = (s8)t6;
}
