extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006A03E0[];

extern int D_006D5FB8;

extern "C" void *func_005F75B0(void) {
    if (D_006D5FB8 == 0) {
        func_005BFB88(&D_006D5FB8, D_006A03E0);
    }
    return &D_006D5FB8;
}
