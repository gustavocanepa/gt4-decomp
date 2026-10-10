typedef int s32;
typedef unsigned int u32;
typedef float f32;

extern "C" s32 func_003765F0(f32 *a, f32 x) {
    s32 i;
    for (i = 0; i < 9; i++) {
        x -= a[i];
        if (x <= 0.0f) break;
    }
    return (u32)i < 9 ? i : 0;
}
