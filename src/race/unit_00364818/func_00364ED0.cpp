typedef int s32;
typedef float f32;

extern "C" f32 func_00364EB8(void **arg0, s32 *arg1);

extern "C" s32 func_00364ED0(void **arg0, s32 *arg1) {
    return (s32)(func_00364EB8(arg0, arg1) * 10.0f);
}
