typedef float f32;

extern "C" f32 func_0057B088(f32 fparg0, f32 fparg1, f32 fparg2) {
    f32 a = fparg0;
    fparg1 = fparg1 - a;
    fparg1 = fparg1 * fparg2;
    a = a + fparg1;
    return a;
}
