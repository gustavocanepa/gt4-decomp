typedef unsigned int u32;

extern "C" void func_005F9D50();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A1C40[];
extern int D_0088F5F0;

extern int D_0088F4D0;

extern "C" void *func_005FA430(void) {
    if (D_0088F4D0 == 0) {
        func_005F9D50();
        func_005BFB68(&D_0088F4D0, D_006A1C40, &D_0088F5F0);
    }
    return &D_0088F4D0;
}
