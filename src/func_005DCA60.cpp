typedef unsigned int u32;

extern "C" void func_005DEA30();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00699198[];
extern int D_0088E3B0;

extern int D_0088E2C0;

extern "C" void *func_005DCA60(void) {
    if (D_0088E2C0 == 0) {
        func_005DEA30();
        func_005BFB68(&D_0088E2C0, D_00699198, &D_0088E3B0);
    }
    return &D_0088E2C0;
}
