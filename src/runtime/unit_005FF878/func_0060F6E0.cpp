extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006C0F80[];

extern int D_006D6208;

extern "C" void *func_0060F6E0(void) {
    if (D_006D6208 == 0) {
        func_005BFB88(&D_006D6208, D_006C0F80);
    }
    return &D_006D6208;
}
