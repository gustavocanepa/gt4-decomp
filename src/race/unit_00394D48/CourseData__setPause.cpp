typedef int s32;
typedef float f32;

extern f32 D_006214DC;

extern "C" void CourseData__evalVMMethods(void *self, s32 on);

extern "C" void CourseData__setPause(void *self, s32 on) {
    if (on) {
        D_006214DC = 0.0f;
        return CourseData__evalVMMethods(self, on);
    }
    D_006214DC = 1.0f / 60.0f;
}
