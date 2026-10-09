typedef float f32;

extern "C" f32 func_0057D488(f32 arg0);
extern "C" f32 func_0057D5A8(f32 arg0);

extern "C" f32 func_0057D6C0(f32 arg0, f32 arg1) {
    f32 result = func_0057D5A8(arg0);
    return func_0057D488(arg1 * result);
}
