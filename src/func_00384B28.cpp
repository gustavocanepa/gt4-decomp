typedef float f32;

extern "C" f32 func_00384B28(f32 *arg0) {
    f32 v = *arg0;

    if (v < -1.0f) {
        v = -1.0f;
    }
    if (v > 1.0f) {
        v = 1.0f;
    }
    return v;
}
