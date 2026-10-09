typedef int s32;
typedef float f32;

extern "C" void func_00451408(void *arg0, s32 arg1, f32 arg2) {
    *(f32 *)((char *)arg0 + arg1 * 4 + 0x64) = arg2;
}
