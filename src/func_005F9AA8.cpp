typedef unsigned int u32;

extern "C" void func_005FA678();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A1BC8[];
extern int D_006D5FC8;

extern int D_0088F450;

extern "C" void *func_005F9AA8(void) {
    if (D_0088F450 == 0) {
        func_005FA678();
        func_005BFB68(&D_0088F450, D_006A1BC8, &D_006D5FC8);
    }
    return &D_0088F450;
}
