typedef unsigned int u32;

extern "C" void func_005E59F8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00698BE0[];
extern int D_0088E610;

extern int D_0088E260;

extern "C" void *func_005DBE28(void) {
    if (D_0088E260 == 0) {
        func_005E59F8();
        func_005BFB68(&D_0088E260, D_00698BE0, &D_0088E610);
    }
    return &D_0088E260;
}
