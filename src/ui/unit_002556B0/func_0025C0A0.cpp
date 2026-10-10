typedef int s32;
typedef float f32;

extern "C" f32 mWidget__getWindowY(void);
extern "C" s32 func_0025BFE0(void *out, f32 a, f32 b);
extern "C" void mWidget__setWindowY(s32 arg0, f32 arg1);

extern "C" s32 func_0025C0A0(s32 arg0, f32 fparg0, f32 fparg1) {
    f32 sp0;
    s32 temp_s0;

    sp0 = mWidget__getWindowY();
    temp_s0 = func_0025BFE0(&sp0, fparg0, fparg1);
    mWidget__setWindowY(arg0, sp0);
    return temp_s0;
}
