typedef float f32;

extern "C" f32 func_00579548();

extern "C" f32 func_005795A0(f32 fparg0, f32 fparg1) {
    return ((fparg1 - fparg0) * func_00579548()) + fparg0;
}
