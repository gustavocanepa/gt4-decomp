typedef float f32;

extern "C" f32 func_003FF380(f32 x, f32 lo, f32 hi, f32 period) {
    if (lo <= x && x <= hi) {
        return x;
    }
    f32 y = x - period;
    if (lo <= y && y <= hi) {
        return y;
    }
    y = x + period;
    if (lo <= y && y <= hi) {
        return y;
    }
    return x;
}
