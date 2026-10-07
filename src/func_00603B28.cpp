extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006A7BE0[];

extern int D_006D60E0;

extern "C" void *func_00603B28(void) {
    if (D_006D60E0 == 0) {
        func_005BFB88(&D_006D60E0, D_006A7BE0);
    }
    return &D_006D60E0;
}
