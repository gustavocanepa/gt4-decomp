typedef int s32;
typedef float f32;

extern s32 D_0088F2D0;

extern "C" void func_00391D58(f32 fparg0, f32 fparg1);

extern "C" void func_00391D98(f32 fparg0) {
    D_0088F2D0 = 0;
    func_00391D58(1.0f, fparg0);
}
