typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64;
typedef float f32; typedef double f64;
#define NULL 0
f32 func_00477460(s32);
void func_00480F78(void *);
void func_00480FA0(void *, s32);
f32 func_0047C248(u32 n, void *arg1) {
    f32 a, b;
    if (n >= 2U) {
        a = func_00477460(*(s32 *)((s8 *)arg1 + 8) - 8);
        func_00480F78(arg1);
        b = func_00477460(*(s32 *)((s8 *)arg1 + 8) - 8);
        func_00480FA0(arg1, n - 1);
        return (a < b) ? a : b;
    }
    func_00480FA0(arg1, n);
    return 0.0f;
}
