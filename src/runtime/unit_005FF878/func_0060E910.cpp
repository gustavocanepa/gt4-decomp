extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006C02D8[];

extern int D_006D61D0;

extern "C" void *func_0060E910(void) {
    if (D_006D61D0 == 0) {
        func_005BFB88(&D_006D61D0, D_006C02D8);
    }
    return &D_006D61D0;
}
