extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006A62A0[];

extern int D_006D60B0;

extern "C" void *func_00602780(void) {
    if (D_006D60B0 == 0) {
        func_005BFB88(&D_006D60B0, D_006A62A0);
    }
    return &D_006D60B0;
}
