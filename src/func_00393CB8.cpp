typedef float f32;

extern "C" f32 func_0057D008(f32 arg0);

extern "C" f32 func_00393CB8(f32 arg0) {
    f32 t = 1.0f - arg0 * arg0;
    __asm__("sqrt.s %0, %1" : "=f"(t) : "f"(t));
    return func_0057D008(arg0 / t);
}
