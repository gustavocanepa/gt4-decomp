extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006AB048[];

extern int D_006D6110;

extern "C" void *func_00604AB0(void) {
    if (D_006D6110 == 0) {
        func_005BFB88(&D_006D6110, D_006AB048);
    }
    return &D_006D6110;
}
