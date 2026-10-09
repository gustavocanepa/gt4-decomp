extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006D3000[];

extern int D_006D6300;

extern "C" void *type_info__tf(void) {
    if (D_006D6300 == 0) {
        func_005BFB88(&D_006D6300, D_006D3000);
    }
    return &D_006D6300;
}
