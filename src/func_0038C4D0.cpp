typedef int s32;
typedef float f32;

struct S0038C4D0 {
    char pad0[4];
    s32 unk4;
};

extern "C" f32 func_0038C4D0(struct S0038C4D0 *arg0) {
    f32 var_f0 = 5.0f;
    if (arg0->unk4 != 0) {
        var_f0 = -1.5f;
    }
    return var_f0;
}
