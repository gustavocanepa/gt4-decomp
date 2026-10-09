extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006A6DA0[];

extern int D_006D60B8;

extern "C" void *func_006033B8(void) {
    if (D_006D60B8 == 0) {
        func_005BFB88(&D_006D60B8, D_006A6DA0);
    }
    return &D_006D60B8;
}
