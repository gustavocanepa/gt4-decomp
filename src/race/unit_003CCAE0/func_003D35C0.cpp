typedef int s32;
typedef float f32;

extern "C" f32 func_003D35C0(s32 arg0) {
    f32 var_f0;

    var_f0 = -1.5707959f;
    if ((arg0 & 1) == 0) {
        var_f0 = 1.5707959f;
    }
    return var_f0;
}
