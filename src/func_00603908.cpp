extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006A7A50[];

extern int D_006D60D0;

extern "C" void *func_00603908(void) {
    if (D_006D60D0 == 0) {
        func_005BFB88(&D_006D60D0, D_006A7A50);
    }
    return &D_006D60D0;
}
