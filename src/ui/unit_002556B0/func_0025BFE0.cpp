typedef float f32;

extern "C" bool func_0025BFE0(f32 *cur, f32 target, f32 rate) {
    f32 d = target - *cur;
    if (d > -1.0f && d < 1.0f) {
        *cur = target;
        return true;
    }
    *cur += d * rate;
    return false;
}
