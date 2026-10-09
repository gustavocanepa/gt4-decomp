typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64;
typedef float f32; typedef double f64;
#define NULL 0
void func_0047DB00(f32 *self, f32 x) {
    while (x > 0x1.68p+7f) {
        x -= 0x1.68p+8f;
    }
    while (x < -0x1.68p+7f) {
        x += 0x1.68p+8f;
    }
    self[11] = x * 0x1.1df468p-6f;
}
