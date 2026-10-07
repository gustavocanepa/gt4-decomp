typedef float f32;

extern "C" f32 func_00578598();

extern "C" f32 func_005792F0(f32 fparg0, f32 fparg1) {
    return ((fparg1 - fparg0) * func_00578598()) + fparg0;
}
