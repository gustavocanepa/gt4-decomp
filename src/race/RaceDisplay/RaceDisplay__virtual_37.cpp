typedef int s32;
typedef float f32;

extern "C" void AutomaticFader__oneshot(s32 arg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4);

extern "C" void RaceDisplay__virtual_37(s32 arg0) {
    AutomaticFader__oneshot(arg0 + 0xBC, 0.0f, 4.0f, 0.0f, 0.25f);
}
