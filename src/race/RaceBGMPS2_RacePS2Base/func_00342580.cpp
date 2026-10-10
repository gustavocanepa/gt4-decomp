typedef int s32;
typedef float f32;

extern "C" void func_004AA1D8(f32 a, f32 b, f32 c, f32 d);
extern "C" void func_004A2808(s32 id, f32 v);
extern "C" void func_004A1638(s32 id);
extern "C" void func_00342630(void *obj);

extern "C" void func_00342580(void *obj, f32 x, f32 y) {
    func_004AA1D8(0.0f, 0.0f, 0.0f, y);
    func_004A2808(0xA9, x);
    func_004A1638(6);
    func_00342630(obj);
}
