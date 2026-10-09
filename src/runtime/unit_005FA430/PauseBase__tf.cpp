extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006A2D08[];

extern int D_006D6030;

extern "C" void *PauseBase__tf(void) {
    if (D_006D6030 == 0) {
        func_005BFB88(&D_006D6030, D_006A2D08);
    }
    return &D_006D6030;
}
