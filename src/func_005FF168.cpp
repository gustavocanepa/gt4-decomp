extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006A42A8[];

extern int D_006D6070;

extern "C" void *func_005FF168(void) {
    if (D_006D6070 == 0) {
        func_005BFB88(&D_006D6070, D_006A42A8);
    }
    return &D_006D6070;
}
