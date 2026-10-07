extern "C" void func_005FB200();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A3BF0[];
extern int D_006D6008;

extern int D_0088F8D0;

extern "C" void *func_005FE478(void) {
    if (D_0088F8D0 == 0) {
        func_005FB200();
        func_005BFB68(&D_0088F8D0, D_006A3BF0, &D_006D6008);
    }
    return &D_0088F8D0;
}
