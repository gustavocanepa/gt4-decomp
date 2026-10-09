typedef int s32;
typedef float f32;

extern "C" void func_003A98E8(s32 arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);

extern "C" void func_003A3AA8(s32 arg0, f32 fparg0) {
    func_003A98E8(arg0 + 0x24, 0.0f, fparg0, 0.5f, 3.0f);
}
