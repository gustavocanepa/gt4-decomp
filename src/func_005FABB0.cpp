extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006A25D8[];

extern int D_006D5FD8;

extern "C" void *func_005FABB0(void) {
    if (D_006D5FD8 == 0) {
        func_005BFB88(&D_006D5FD8, D_006A25D8);
    }
    return &D_006D5FD8;
}
