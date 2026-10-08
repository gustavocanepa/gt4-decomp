typedef int s32;
typedef float f32;

extern "C" void func_00379F80(char *arg0, f32 fparg0, f32 fparg1) {
    *(f32 *)(arg0 + 0x28C) = fparg0;
    *(s32 *)(arg0 + 0x27C) = 4;
    *(f32 *)(arg0 + 0x290) = fparg1;
    *(s32 *)(arg0 + 0x144) = 0;
}
