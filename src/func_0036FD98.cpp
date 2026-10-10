/* Register allocation found by a random search over which fields are read into locals (build/scratch/os2c/perm36.py). */
typedef float f32;

struct Obj_0036FD98 {
    char pad[8];
    f32 m8;
    f32 mC;
    f32 m10;
    f32 m14;
    f32 m18;
};
extern "C" f32 func_0036FD98(Obj_0036FD98 *arg0) {
    f32 c = arg0->mC;
    f32 w = arg0->m8;
    f32 area = w * arg0->m10;
    f32 y = arg0->m14;
    f32 r;
    if (arg0->m18 / c < y / area) {
        r = arg0->m18;
    } else {
        r = y * c / area;
    }
    return r;
}
