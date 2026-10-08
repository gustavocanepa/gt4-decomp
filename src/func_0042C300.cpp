typedef int s32;
typedef float f32;

extern "C" f32 func_0042B440(s32 arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6);

extern "C" f32 func_0042C300(s32 arg0, s32 arg1, f32 arg2, s32 arg3) {
    f32 z = 0.0f;
    return func_0042B440(arg0, arg1, arg2, z, z, 0, arg3);
}
