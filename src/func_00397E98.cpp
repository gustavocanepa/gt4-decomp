typedef float f32;

struct Vec3 {
    f32 x, y, z;
};

extern Vec3 D_00621500;
extern f32 D_0062150C;
extern "C" void func_004A3F98(f32, f32, f32);

extern "C" void func_00397E98(void) {
    f32 s = D_0062150C;
    func_004A3F98(D_00621500.x * s, D_00621500.y * s, D_00621500.z * s);
}
