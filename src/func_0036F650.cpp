typedef int s32;
typedef float f32;

extern "C" f32 func_0036F650(s32 arg0) {
    if (arg0 <= 0) {
        arg0 = 0;
    }
    if (arg0 >= 0x14) {
        arg0 = 0x14;
    }
    return *(f32 *)(0x620F40 + (arg0 * 4));
}
