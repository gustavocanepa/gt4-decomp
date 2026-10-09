extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006A2680[];

extern int D_006D6000;

extern "C" void *func_005FB0B0(void) {
    if (D_006D6000 == 0) {
        func_005BFB88(&D_006D6000, D_006A2680);
    }
    return &D_006D6000;
}
