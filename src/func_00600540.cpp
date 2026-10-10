typedef float f32;
typedef int s32;

extern "C" f32 func_00600540(char *arg0, s32 arg1) {
    arg0 = arg0 + arg1 * 4;
    return *(f32 *)(arg0 + 0x8);
}
