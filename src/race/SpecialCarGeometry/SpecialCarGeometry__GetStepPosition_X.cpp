typedef int s32;
typedef float f32;

extern "C" f32 SpecialCarGeometry__GetStepPosition_X(void *arg0, s32 arg1) {
    f32 var_f0 = -0.225f;
    if (arg1 != 0) {
        var_f0 = 0.225f;
    }
    return var_f0;
}
