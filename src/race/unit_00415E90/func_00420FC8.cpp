typedef float f32;

extern "C" f32 *func_00420F70(f32 *arg0, f32 fparg0);

extern "C" f32 *func_00420FC8(f32 *arg0, f32 *arg1) {
    return func_00420F70(arg0, *arg1);
}
