typedef float f32;

extern "C" f32 func_0037E9A8(f32 x) {
    f32 t = x;
    x = (x * 0x1.b6db6p-2f + -0x1.b6db6p-2f) * x * x + t;
    return 2.0f / (x * 10.0f + 1.5f);
}
