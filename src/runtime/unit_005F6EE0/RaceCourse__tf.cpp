extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006A0368[];

extern int D_006D5FB0;

extern "C" void *RaceCourse__tf(void) {
    if (D_006D5FB0 == 0) {
        func_005BFB88(&D_006D5FB0, D_006A0368);
    }
    return &D_006D5FB0;
}
