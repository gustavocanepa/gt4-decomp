typedef int s32;
typedef float f32;

extern "C" s32 func_00567F58(s32 arg0, f32 arg1, s32 arg2);

extern "C" s32 func_0056DD50(s32 arg0, s32 arg1, s32 arg2) {
    return func_00567F58(arg0, 1.0f, arg2);
}
