typedef int s32;

extern "C" s32 func_001D3AB8(void *a0);

extern char D_008290D8[];

extern s32 D_00618D7C;

extern "C" void *func_001D3A60(void) {
    if (D_00618D7C == 0) {
        s32 t = func_001D3AB8(D_008290D8);
        D_00618D7C = 1;
        (void)t;
    }
    return D_008290D8;
}
