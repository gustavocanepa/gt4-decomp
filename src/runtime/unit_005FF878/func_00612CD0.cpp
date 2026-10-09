extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006CC510[];

extern int D_006D62A0;

extern "C" void *func_00612CD0(void) {
    if (D_006D62A0 == 0) {
        func_005BFB88(&D_006D62A0, D_006CC510);
    }
    return &D_006D62A0;
}
