typedef int s32;

extern s32 D_00618D80;
extern s32 D_00829100;

extern "C" s32 *func_001D3AF8(void) {
    if (D_00618D80 == 0) {
        D_00618D80 = 1;
        D_00829100 = 0;
    }
    return &D_00829100;
}
