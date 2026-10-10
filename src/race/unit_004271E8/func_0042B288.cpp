typedef int s32;
typedef float f32;

extern "C" void func_0042B288(f32 *a, const f32 *b, s32 n, f32 t) {
    if (n > 0) {
        f32 k = 1.0f - t;
        do {
            *a = *a * k + *b++ * t;
            a++;
        } while (--n != 0);
    }
}
