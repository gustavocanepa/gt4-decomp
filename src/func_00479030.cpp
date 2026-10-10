typedef float f32;

extern "C" void func_0047DE58(f32 *out, const f32 *a, const f32 *b, f32 t);

extern "C" void func_00479030(f32 *out, const f32 *a, const f32 *b, f32 t) {
    *out++ = *a++ * (1.0f - t) + *b++ * t;
    func_0047DE58(out, a, b, t);
}
