typedef unsigned int u32;

extern "C" void func_005E5760();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069B1B0[];
extern int D_0088E5D0;

extern int D_0088E630;

extern "C" void *func_005E5A98(void) {
    if (D_0088E630 == 0) {
        func_005E5760();
        func_005BFB68(&D_0088E630, D_0069B1B0, &D_0088E5D0);
    }
    return &D_0088E630;
}
