typedef int s32;
typedef float f32;

extern "C" void func_003A98E8(s32 arg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4);

extern "C" void RaceDisplay__virtual_37(s32 arg0) {
    func_003A98E8(arg0 + 0xBC, 0.0f, 4.0f, 0.0f, 0.25f);
}
