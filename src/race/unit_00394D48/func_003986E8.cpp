typedef float f32;

struct Vec3 {
    f32 x, y, z;
};

typedef int s32;

extern "C" void func_00398758(s32 arg0, struct Vec3 *arg1);
extern "C" void func_004523B0(f32 arg0, f32 arg1, f32 arg2);

extern "C" void func_003986E8(s32 arg0) {
    struct Vec3 v;
    func_00398758(arg0, &v);
    func_004523B0(v.x, v.y, v.z);
}
