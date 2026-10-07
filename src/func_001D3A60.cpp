typedef int s32;

extern "C" s32 func_001D3AB8(void *a0);

extern char D_00844348[];

static s32 D_00621348;

extern "C" void *func_001D3A60(void) {
    if (D_00621348 == 0) {
        s32 t = func_001D3AB8(D_00844348);
        D_00621348 = 1;
        (void)t;
    }
    return D_00844348;
}
