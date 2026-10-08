typedef float f32;

extern "C" f32 func_0037A418(f32 fparg0, f32 fparg1, f32 fparg2) {
    f32 var_f14 = fparg2;
    f32 temp_f12 = fparg0 - 0.5f;
    f32 temp_f0 = (fparg1 - var_f14) * temp_f12;

    if (temp_f12 < 0.0f) {
        var_f14 = -var_f14;
    }
    return var_f14 + (temp_f0 + temp_f0);
}
