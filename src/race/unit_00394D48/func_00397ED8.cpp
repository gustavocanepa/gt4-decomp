typedef float f32;

extern "C" void func_004A6100(f32 r, f32 g, f32 b, f32 a);
extern "C" void func_004A60E0(f32 r, f32 g, f32 b, f32 a);

extern "C" void func_00397ED8(void) {
    func_004A6100(0.0f, 0.0f, 0.0f, 0.0f);
    func_004A60E0(1.0f, 1.0f, 1.0f, 1.0f);
}
