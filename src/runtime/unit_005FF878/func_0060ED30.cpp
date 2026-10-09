extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006C0768[];

extern int D_006D61E0;

extern "C" void *func_0060ED30(void) {
    if (D_006D61E0 == 0) {
        func_005BFB88(&D_006D61E0, D_006C0768);
    }
    return &D_006D61E0;
}
