typedef int s32;
typedef float f32;

extern "C" f32 MTRGeometry__getSeatY(s32 arg0, s32 arg1) {
    f32 var_f0 = 0.251f;
    if (arg1 == 0) {
        var_f0 = 0.281f;
    }
    return var_f0;
}
