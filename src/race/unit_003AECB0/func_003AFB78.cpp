typedef int s32;
typedef float f32;

extern "C" void RaceDisplayUtil__fillRectangle(f32, f32, f32, f32);

extern "C" void func_003AFB78(s32 x, s32 y, s32 w, s32 h) {
    RaceDisplayUtil__fillRectangle((f32)x, (f32)y, (f32)(x + w), (f32)(y + h));
}
