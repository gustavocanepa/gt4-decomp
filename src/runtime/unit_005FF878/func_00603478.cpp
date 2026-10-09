extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006A6F78[];

extern int D_006D60C0;

extern "C" void *func_00603478(void) {
    if (D_006D60C0 == 0) {
        func_005BFB88(&D_006D60C0, D_006A6F78);
    }
    return &D_006D60C0;
}
