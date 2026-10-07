typedef int s32;
typedef float f32;

extern "C" f32 func_0025B2B0(void);
extern "C" s32 func_0025BFE0(void *out, f32 a, f32 b);
extern "C" void func_0025B2E0(s32 arg0, f32 arg1);

extern "C" s32 func_0025C030(s32 arg0, f32 fparg0, f32 fparg1) {
    f32 sp0;
    s32 temp_s0;

    sp0 = func_0025B2B0();
    temp_s0 = func_0025BFE0(&sp0, fparg0, fparg1);
    func_0025B2E0(arg0, sp0);
    return temp_s0;
}
