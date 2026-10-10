/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

extern "C" f32 func_0057AE68(s32 positive, f32 x, f32 y) {
    f32 r = x - (f32)(s32)(x / y) * y;
    if (positive && x < 0.0f) {
        r += y;
    }
    return r;
}
