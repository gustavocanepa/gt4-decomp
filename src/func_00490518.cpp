typedef float f32;
typedef int s32;

extern "C" void func_004904E8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern "C" void func_00490518(s32 arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    func_004904E8(arg0,
        (s32)(fparg0 * 255.0f) & 0xFF,
        (s32)(fparg1 * 255.0f) & 0xFF,
        (s32)(fparg2 * 255.0f) & 0xFF,
        (s32)(fparg3 * 128.0f) & 0xFF);
}
