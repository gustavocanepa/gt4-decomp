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

extern "C" void func_004400D0(void *, s32);
extern "C" s32 func_004452A8(void *, s32, u8, u8);

struct func_00440820_arg0 {
    char pad0[0x490];
    s32 unk490;
};
struct func_00440820_v_s0 {
    char pad0[0xE0];
    s64 unkE0;
    char padE8[0x6F];
    s8 unk157;
    s8 unk158;
    s8 unk159;
    s8 unk15A;
};
struct func_00440820_arg2 {
    char pad0[0x11E];
    u8 unk11E;
    char pad11F[0x2];
    u8 unk121;
    char pad122[0x2];
    u8 unk124;
    char pad125[0x2];
    u8 unk127;
    char pad128[0x1];
    u8 unk129;
    char pad12A[0x2];
    u8 unk12C;
    char pad12D[0x2];
    u8 unk12F;
    char pad130[0x2];
    u8 unk132;
};

extern "C" void func_00440820(s32 *arg0, void *arg1, s32 arg2) {
    char *v_s0;
    s32 t1;
    s32 t2;
    s32 t3;
    s32 t4;
    v_s0 = (char *)arg0 + (((((((struct func_00440820_arg0 *)arg0)->unk490 << 1) + ((struct func_00440820_arg0 *)arg0)->unk490) << 4) - ((struct func_00440820_arg0 *)arg0)->unk490) << 3);
    v_s0 = (char *)v_s0 + 0x8;
    ((struct func_00440820_v_s0 *)v_s0)->unkE0 = (s64)arg1;
    func_004400D0(arg0, arg2);
    t1 = func_004452A8(v_s0, 0x1, ((struct func_00440820_arg2 *)arg2)->unk121, ((struct func_00440820_arg2 *)arg2)->unk11E);
    ((struct func_00440820_v_s0 *)v_s0)->unk157 = (s8)t1;
    t2 = func_004452A8(v_s0, 0x1, ((struct func_00440820_arg2 *)arg2)->unk127, ((struct func_00440820_arg2 *)arg2)->unk124);
    ((struct func_00440820_v_s0 *)v_s0)->unk158 = (s8)t2;
    t3 = func_004452A8(v_s0, 0x1, ((struct func_00440820_arg2 *)arg2)->unk12C, ((struct func_00440820_arg2 *)arg2)->unk129);
    ((struct func_00440820_v_s0 *)v_s0)->unk159 = (s8)t3;
    t4 = func_004452A8(v_s0, 0x1, ((struct func_00440820_arg2 *)arg2)->unk132, ((struct func_00440820_arg2 *)arg2)->unk12F);
    ((struct func_00440820_v_s0 *)v_s0)->unk15A = (s8)t4;
}
