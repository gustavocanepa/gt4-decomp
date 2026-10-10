typedef float f32;
typedef int s32;

extern "C" f32 *func_004A5B70(s32 arg0);
extern "C" void func_0049FD50(s32 arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

extern "C" void RaceDisplayUtil__fillRectangle(f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    volatile f32 *v = func_004A5B70(3);

    v[0] = fparg0;
    v[1] = fparg1;
    v[2] = 0.0f;
    v[3] = fparg2;
    v[4] = fparg1;
    v[5] = 0.0f;
    v[6] = fparg0;
    v[7] = fparg3;
    v[8] = 0.0f;
    v[9] = fparg2;
    v[10] = fparg3;
    v[11] = 0.0f;

    func_0049FD50(4, (void *)v, 0, 0, 0, 0);
}
