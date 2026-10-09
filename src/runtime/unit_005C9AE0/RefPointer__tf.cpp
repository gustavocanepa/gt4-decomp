extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_0068FD50[];

extern int D_006D5E20;

extern "C" void *RefPointer__tf(void) {
    if (D_006D5E20 == 0) {
        func_005BFB88(&D_006D5E20, D_0068FD50);
    }
    return &D_006D5E20;
}
