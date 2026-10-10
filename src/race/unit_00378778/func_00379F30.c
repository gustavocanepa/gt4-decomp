typedef int s32;
typedef float f32;
void func_00379F30(char *arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2) {
    *(s32 *)(arg0 + 0x27C) = 1;
    *(f32 *)(arg0 + 0x284) = fparg0;
    *(f32 *)(arg0 + 0x288) = fparg1;
    *(f32 *)(arg0 + 0x280) = fparg2;
    *(s32 *)(arg0 + 0x294) = arg1;
}
