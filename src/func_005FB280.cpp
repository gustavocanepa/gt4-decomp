extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006A2760[];

extern int D_006D6010;

extern "C" void *func_005FB280(void) {
    if (D_006D6010 == 0) {
        func_005BFB88(&D_006D6010, D_006A2760);
    }
    return &D_006D6010;
}
