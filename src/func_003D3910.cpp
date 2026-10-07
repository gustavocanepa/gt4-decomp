typedef float f32;
typedef int s32;

extern "C" s32 func_003D3950(f32 arg0, f32 arg1, f32 arg2, f32 arg3);

extern "C" s32 func_003D3910(f32 arg0, f32 arg1, f32 arg2) {
    return func_003D3950(arg0, arg1, arg2, 1.0f);
}
