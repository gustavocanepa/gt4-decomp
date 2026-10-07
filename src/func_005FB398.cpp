typedef unsigned int u32;

extern "C" void func_005F76F8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A2838[];
extern int D_0088F330;

extern int D_0088F710;

extern "C" void *func_005FB398(void) {
    if (D_0088F710 == 0) {
        func_005F76F8();
        func_005BFB68(&D_0088F710, D_006A2838, &D_0088F330);
    }
    return &D_0088F710;
}
