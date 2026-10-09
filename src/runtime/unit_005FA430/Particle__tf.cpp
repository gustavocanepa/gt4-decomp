extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006A2A50[];

extern int D_006D6020;

extern "C" void *Particle__tf(void) {
    if (D_006D6020 == 0) {
        func_005BFB88(&D_006D6020, D_006A2A50);
    }
    return &D_006D6020;
}
