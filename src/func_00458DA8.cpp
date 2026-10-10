typedef float f32;

extern "C" f32 func_00458740(void *self, int which);
extern "C" void func_00458E08(void *self, f32 value);

extern "C" void func_00458DA8(void *self, int which, int negate) {
    if (!which)
        return;
    f32 v = func_00458740(self, which);
    if (v != 0.0f)
        func_00458E08(self, negate ? -v : v);
}
