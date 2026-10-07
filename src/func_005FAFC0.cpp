extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006A25F8[];

extern int D_006D5FE0;

extern "C" void *func_005FAFC0(void) {
    if (D_006D5FE0 == 0) {
        func_005BFB88(&D_006D5FE0, D_006A25F8);
    }
    return &D_006D5FE0;
}
