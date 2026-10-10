typedef float f32;
f32 func_003F44A0(void *arg0, void *arg1, f32 fparg0, f32 fparg1) {
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f3;
    f32 var_f2;

    temp_f1 = *(f32 *)((char *)arg1 + 0x640);
    var_f2 = 0.0f;
    temp_f3 = *(f32 *)(*(char **)((char *)arg1 + 0x10) + 8);
    if (temp_f1 > 27.777775f) {
        temp_f1_2 = temp_f1 + (temp_f1 * 0.5f);
        if ((fparg0 < 0.0f) && (-temp_f1_2 < fparg0) && (-temp_f3 < fparg1) && (fparg1 < temp_f3)) {
            var_f2 = (temp_f1_2 + fparg0) / temp_f1_2;
        }
    }
    return var_f2;
}
