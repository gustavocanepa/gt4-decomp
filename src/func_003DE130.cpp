typedef int s32;
typedef float f32;

struct Curve_003DE130 {
    char pad0[0x14];
    f32 step;
    char pad18[0x34 - 0x18];
    s32 count;
    f32 *keys;
};

extern "C" s32 func_003DE130(Curve_003DE130 *c, s32 n, f32 x) {
    f32 t = x + (f32)n * c->step;
    s32 i;
    for (i = c->count - 1; i >= 0; i--) {
        if (c->keys[i] < t) {
            return i;
        }
    }
    return -1;
}
