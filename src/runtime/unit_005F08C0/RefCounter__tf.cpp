extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_0069ECC8[];

extern int D_006D5F58;

extern "C" void *RefCounter__tf(void) {
    if (D_006D5F58 == 0) {
        func_005BFB88(&D_006D5F58, D_0069ECC8);
    }
    return &D_006D5F58;
}
