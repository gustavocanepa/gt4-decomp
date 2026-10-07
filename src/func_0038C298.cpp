typedef float f32;
typedef int s32;

struct S0038C298 {
    char pad0[4];
    s32 unk4;
};

extern "C" f32 func_0038C298(S0038C298 *arg0) {
    f32 var_f0 = 0.0229999982f;
    if (arg0->unk4 != 0) {
        var_f0 = -0.031999998f;
    }
    return var_f0;
}
