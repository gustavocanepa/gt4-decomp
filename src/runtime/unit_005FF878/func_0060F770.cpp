extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006C0FF8[];

extern int D_006D6218;

extern "C" void *func_0060F770(void) {
    if (D_006D6218 == 0) {
        func_005BFB88(&D_006D6218, D_006C0FF8);
    }
    return &D_006D6218;
}
