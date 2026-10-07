extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006A3160[];

static int D_006D5E18;

extern "C" void *func_005FDC20(void) {
    if (D_006D5E18 == 0) {
        func_005BFB88(&D_006D5E18, D_006A3160);
    }
    return &D_006D5E18;
}
