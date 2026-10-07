typedef unsigned int u32;

extern "C" void func_005D4F58();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069C1D8[];
extern int D_0088E000;

extern int D_0088E800;

extern "C" void *func_005E87B8(void) {
    if (D_0088E800 == 0) {
        func_005D4F58();
        func_005BFB68(&D_0088E800, D_0069C1D8, &D_0088E000);
    }
    return &D_0088E800;
}
