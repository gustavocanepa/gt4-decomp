typedef float f32;

extern "C" f32 func_00458740(void *self, int which);
extern "C" void GT4Model__CarData__offsetBrake(void *self, f32 value);

extern "C" void func_00458DA8(void *self, int which, int negate) {
    if (!which)
        return;
    f32 v = func_00458740(self, which);
    if (v != 0.0f)
        GT4Model__CarData__offsetBrake(self, negate ? -v : v);
}
