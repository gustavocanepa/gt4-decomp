typedef int s32;
typedef float f32;

extern "C" f32 func_0036F678(s32 arg0) {
    s32 idx = arg0;
    if (idx <= 0) {
        idx = 0;
    }
    if (idx >= 0xB) {
        idx = 0xB;
    }
    return *(f32 *)(0x620F98 + idx * 4);
}
