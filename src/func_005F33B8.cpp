typedef unsigned int u32;

extern "C" void func_006123B0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069F1B8[];
extern int D_008A1AB0;

extern int D_0088EFB0;

extern "C" void *func_005F33B8(void) {
    if (D_0088EFB0 == 0) {
        func_006123B0();
        func_005BFB68(&D_0088EFB0, D_0069F1B8, &D_008A1AB0);
    }
    return &D_0088EFB0;
}
