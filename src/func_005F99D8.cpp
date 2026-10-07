typedef unsigned int u32;

extern "C" void func_005FA678();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A1B90[];
extern int D_006D5FC8;

extern int D_0088F510;

extern "C" void *func_005F99D8(void) {
    if (D_0088F510 == 0) {
        func_005FA678();
        func_005BFB68(&D_0088F510, D_006A1B90, &D_006D5FC8);
    }
    return &D_0088F510;
}
