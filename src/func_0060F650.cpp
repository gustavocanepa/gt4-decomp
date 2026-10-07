extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006C0F08[];

extern int D_006D6220;

extern "C" void *func_0060F650(void) {
    if (D_006D6220 == 0) {
        func_005BFB88(&D_006D6220, D_006C0F08);
    }
    return &D_006D6220;
}
