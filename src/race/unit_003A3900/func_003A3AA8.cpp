typedef int s32;
typedef float f32;

extern "C" void AutomaticFader__oneshot(s32 arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);

extern "C" void func_003A3AA8(s32 arg0, f32 fparg0) {
    AutomaticFader__oneshot(arg0 + 0x24, 0.0f, fparg0, 0.5f, 3.0f);
}
