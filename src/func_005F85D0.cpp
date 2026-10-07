typedef unsigned int u32;

extern "C" void func_005FA678();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A1930[];
extern int D_006D5FC8;

extern int D_0088F5E0;

extern "C" void *func_005F85D0(void) {
    if (D_0088F5E0 == 0) {
        func_005FA678();
        func_005BFB68(&D_0088F5E0, D_006A1930, &D_006D5FC8);
    }
    return &D_0088F5E0;
}
