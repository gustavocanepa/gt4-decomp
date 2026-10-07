typedef unsigned int u32;

extern "C" void func_005F5550();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A42C8[];
extern int D_0088F0B0;

extern int D_0088FA30;

extern "C" void *func_005FF1E0(void) {
    if (D_0088FA30 == 0) {
        func_005F5550();
        func_005BFB68(&D_0088FA30, D_006A42C8, &D_0088F0B0);
    }
    return &D_0088FA30;
}
