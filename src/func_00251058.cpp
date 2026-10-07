typedef int s32;
typedef float f32;

extern "C" void func_00251058(void *arg0, s32 arg1, s32 arg2, f32 arg3) {
    *(f32 *)((char *)arg0 + (((arg1 * 4) + arg2) * 4) + 0x2C) = arg3;
}
