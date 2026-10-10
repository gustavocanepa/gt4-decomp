typedef float f32;
typedef int s32;
void func_003D4A58(char *arg0, s32 arg1, f32 *arg2, f32 *arg3) {
    if (arg1 == 0) {
        *arg2 = *(f32 *)(arg0 + 0x34);
        *arg3 = *(f32 *)(arg0 + 0x38);
        return;
    }
    *arg2 = *(f32 *)(arg0 + 0x24);
    *arg3 = *(f32 *)(arg0 + 0x28);
}
