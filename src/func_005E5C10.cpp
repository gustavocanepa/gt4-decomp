typedef unsigned int u32;

extern "C" void func_005E5668();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069B308[];
extern int D_0088E5C0;

extern int D_0088E660;

extern "C" void *func_005E5C10(void) {
    if (D_0088E660 == 0) {
        func_005E5668();
        func_005BFB68(&D_0088E660, D_0069B308, &D_0088E5C0);
    }
    return &D_0088E660;
}
