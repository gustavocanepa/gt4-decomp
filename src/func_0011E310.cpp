typedef float f32;

extern "C" f32 func_0011E310(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 inv = 1.0f / (arg1 - arg0);
    return (((arg3 - arg2) * arg4) + ((arg2 * arg1) - (arg3 * arg0))) * inv;
}
