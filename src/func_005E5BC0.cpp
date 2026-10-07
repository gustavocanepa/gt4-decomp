typedef unsigned int u32;

extern "C" void func_005E5668();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069B2B0[];
extern int D_0088E5C0;

extern int D_0088E650;

extern "C" void *func_005E5BC0(void) {
    if (D_0088E650 == 0) {
        func_005E5668();
        func_005BFB68(&D_0088E650, D_0069B2B0, &D_0088E5C0);
    }
    return &D_0088E650;
}
