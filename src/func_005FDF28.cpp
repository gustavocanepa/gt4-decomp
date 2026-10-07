typedef unsigned int u32;

extern "C" void func_005FB200();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A3628[];
extern int D_006D6008;

extern int D_0088F860;

extern "C" void *func_005FDF28(void) {
    if (D_0088F860 == 0) {
        func_005FB200();
        func_005BFB68(&D_0088F860, D_006A3628, &D_006D6008);
    }
    return &D_0088F860;
}
