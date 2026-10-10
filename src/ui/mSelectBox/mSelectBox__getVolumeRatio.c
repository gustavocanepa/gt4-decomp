typedef int s32;
typedef float f32;
f32 mWidget__getWindowW(void *);
f32 mWidget__getWindowH(void *);
f32 func_002D4980(void *);
s32 func_0057CE60(void *);
f32 mSelectBox__getVolumeRatio(char *arg0) {
    f32 temp_f20;
    f32 var_f0;
    f32 var_f21;
    s32 temp_v0;

    temp_v0 = *(s32 *)(arg0 + 0xB0);
    if (temp_v0 == 0) var_f21 = *(f32 *)(arg0 + 0xE4); else var_f21 = *(f32 *)(arg0 + 0xE8);
    if (temp_v0 == 0) {
        var_f0 = mWidget__getWindowW(arg0);
    } else {
        var_f0 = mWidget__getWindowH(arg0);
    }
    temp_f20 = var_f21 + func_002D4980(arg0);
    return var_f0 / ((temp_f20 * (f32) (func_0057CE60(arg0 + 0xBC) - 1)) + (var_f21 * *(f32 *)(arg0 + 0xD4)));
}
