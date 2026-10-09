extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006C0840[];

extern int D_006D61F8;

extern "C" void *func_0060F110(void) {
    if (D_006D61F8 == 0) {
        func_005BFB88(&D_006D61F8, D_006C0840);
    }
    return &D_006D61F8;
}
