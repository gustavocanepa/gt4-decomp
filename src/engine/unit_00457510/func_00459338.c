typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64;
typedef float f32; typedef double f64;
#define NULL 0
f32 func_00459338(f32 x) {
    if (x < -0x1.c2p+12f || x > 0x1.c2p+12f) {
        return 0.0f;
    }
    while (x < 0.0f) {
        x += 0x1.68p+8f;
    }
    while (x >= 0x1.68p+8f) {
        x -= 0x1.68p+8f;
    }
    return x;
}
