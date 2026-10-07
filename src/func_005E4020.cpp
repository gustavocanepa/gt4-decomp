typedef unsigned int u32;

extern "C" void func_005D4F58();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069A790[];
extern int D_0088E000;

extern int D_0088E4C0;

extern "C" void *func_005E4020(void) {
    if (D_0088E4C0 == 0) {
        func_005D4F58();
        func_005BFB68(&D_0088E4C0, D_0069A790, &D_0088E000);
    }
    return &D_0088E4C0;
}
