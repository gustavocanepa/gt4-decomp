typedef int s32;
typedef signed char s8;
typedef float f32;

struct Sub_003F33A8 {
    char pad0[0x10DC];
    f32 unk10DC;
};

struct Obj_003F33A8 {
    char pad0[0x10];
    Sub_003F33A8 *unk10;
    char pad1[0x6C4 - 0x14];
    s8 unk6C4;
};

extern "C" f32 func_003F33A8(Obj_003F33A8 *arg0, s32 *arg1) {
    *arg1 = 0;
    if (arg0->unk6C4 == 1) {
        return arg0->unk10->unk10DC;
    }
    return 0.0f;
}
