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

extern "C" void func_0043FEA0(void *, s32);
extern "C" s32 func_004452A8(void *, u16, u16, u16);

struct func_004402F0_arg0 {
    char pad0[0x490];
    s32 unk490;
};
struct func_004402F0_v_s0 {
    char pad0[0x48];
    s64 unk48;
    char pad50[0xC0];
    s16 unk110;
    s16 unk112;
    s16 unk114;
    s16 unk116;
    s16 unk118;
    s16 unk11A;
    s16 unk11C;
    s16 unk11E;
    char pad120[0x8];
    s16 unk128;
    s8 unk12A;
    char pad12B[0x1];
    s16 unk12C;
};
struct func_004402F0_arg2 {
    char pad0[0x24];
    u16 unk24;
    u16 unk26;
    u16 unk28;
    char pad2A[0x8];
    u8 unk32;
    u8 unk33;
    u8 unk34;
};

extern "C" void func_004402F0(s32 *arg0, void *arg1, s32 arg2) {
    char *v_s0;
    s32 t1;
    s32 t2;
    v_s0 = (char *)arg0 + (((((((struct func_004402F0_arg0 *)arg0)->unk490 << 1) + ((struct func_004402F0_arg0 *)arg0)->unk490) << 4) - ((struct func_004402F0_arg0 *)arg0)->unk490) << 3);
    v_s0 = (char *)v_s0 + 0x8;
    ((struct func_004402F0_v_s0 *)v_s0)->unk48 = (s64)arg1;
    func_0043FEA0(arg0, arg2);
    ((struct func_004402F0_v_s0 *)v_s0)->unk110 = (s16)*(u16 *)((char *)arg2 + 0x22);
    ((struct func_004402F0_v_s0 *)v_s0)->unk112 = (s16)*(u16 *)((char *)arg2 + 0xc);
    ((struct func_004402F0_v_s0 *)v_s0)->unk114 = (s16)*(u16 *)((char *)arg2 + 0xe);
    ((struct func_004402F0_v_s0 *)v_s0)->unk116 = (s16)*(u16 *)((char *)arg2 + 0x10);
    ((struct func_004402F0_v_s0 *)v_s0)->unk118 = (s16)*(u16 *)((char *)arg2 + 0x12);
    ((struct func_004402F0_v_s0 *)v_s0)->unk11A = (s16)*(u16 *)((char *)arg2 + 0x14);
    ((struct func_004402F0_v_s0 *)v_s0)->unk11C = (s16)*(u16 *)((char *)arg2 + 0x16);
    ((struct func_004402F0_v_s0 *)v_s0)->unk11E = (s16)*(u16 *)((char *)arg2 + 0x18);
    t1 = func_004452A8(v_s0, ((struct func_004402F0_arg2 *)arg2)->unk24, ((struct func_004402F0_arg2 *)arg2)->unk28, ((struct func_004402F0_arg2 *)arg2)->unk26);
    ((struct func_004402F0_v_s0 *)v_s0)->unk128 = (s16)t1;
    t2 = func_004452A8(v_s0, ((struct func_004402F0_arg2 *)arg2)->unk32, ((struct func_004402F0_arg2 *)arg2)->unk34, ((struct func_004402F0_arg2 *)arg2)->unk33);
    ((struct func_004402F0_v_s0 *)v_s0)->unk12A = (s8)t2;
    ((struct func_004402F0_v_s0 *)v_s0)->unk12C = (s16)*(u16 *)((char *)v_s0 + 0x128);
}
