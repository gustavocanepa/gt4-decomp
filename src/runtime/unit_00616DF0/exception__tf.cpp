extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006D31E0[];

extern int D_006D6308;

extern "C" void *exception__tf(void) {
    if (D_006D6308 == 0) {
        func_005BFB88(&D_006D6308, D_006D31E0);
    }
    return &D_006D6308;
}
