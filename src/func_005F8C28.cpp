typedef unsigned int u32;

extern "C" void func_005FA678();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A19E8[];
extern int D_006D5FC8;

extern int D_0088F560;

extern "C" void *func_005F8C28(void) {
    if (D_0088F560 == 0) {
        func_005FA678();
        func_005BFB68(&D_0088F560, D_006A19E8, &D_006D5FC8);
    }
    return &D_0088F560;
}
