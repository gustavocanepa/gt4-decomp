extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006AA838[];

extern int D_006D6100;

extern "C" void *func_00603D80(void) {
    if (D_006D6100 == 0) {
        func_005BFB88(&D_006D6100, D_006AA838);
    }
    return &D_006D6100;
}
