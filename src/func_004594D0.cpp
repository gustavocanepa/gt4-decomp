typedef float f32;

extern "C" void func_004593D0(f32 *a, f32 *b);

extern "C" f32 func_004594D0(f32 a, f32 b, f32 t) {
    func_004593D0(&a, &b);
    return a * t + b * (0x1.000000p+0f - t);
}
