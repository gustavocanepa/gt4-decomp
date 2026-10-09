extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006AA860[];

extern int D_006D6108;

extern "C" void *CarDataBase__tf(void) {
    if (D_006D6108 == 0) {
        func_005BFB88(&D_006D6108, D_006AA860);
    }
    return &D_006D6108;
}
