typedef int s32;
typedef float f32;

extern f32 D_006214DC;

extern "C" void func_00397638(void *self, s32 on);

extern "C" void func_00396A90(void *self, s32 on) {
    if (on) {
        D_006214DC = 0.0f;
        return func_00397638(self, on);
    }
    D_006214DC = 1.0f / 60.0f;
}
