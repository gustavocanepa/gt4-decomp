extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006CC5A0[];

extern int D_006D62B0;

extern "C" void *func_00612F10(void) {
    if (D_006D62B0 == 0) {
        func_005BFB88(&D_006D62B0, D_006CC5A0);
    }
    return &D_006D62B0;
}
