typedef int s32;
typedef float f32;

struct S00395400 {
    char pad0[0x4];
    s32 unk4;
};

struct S00396800_ret {
    char pad0[0x14];
    f32 unk14;
};

extern "C" struct S00396800_ret *func_00396800(s32 arg0);

extern "C" f32 func_00395400(struct S00395400 *arg0) {
    return func_00396800(arg0->unk4)->unk14;
}
