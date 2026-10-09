typedef float f32;

struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
};

extern Vec3 D_00621D18;

extern "C" void func_003E50E0(Vec3 *arg0) {
    D_00621D18.x = arg0->x;
    D_00621D18.y = arg0->y;
    D_00621D18.z = arg0->z;
}
