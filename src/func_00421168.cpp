typedef float f32;

extern "C" f32 *func_00421110(f32 *arg0, f32 fparg0);

extern "C" f32 *func_00421168(f32 *arg0, f32 *arg1) {
    return func_00421110(arg0, *arg1);
}
