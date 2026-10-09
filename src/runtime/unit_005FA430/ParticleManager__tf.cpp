extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006A2A38[];

extern int D_006D6028;

extern "C" void *ParticleManager__tf(void) {
    if (D_006D6028 == 0) {
        func_005BFB88(&D_006D6028, D_006A2A38);
    }
    return &D_006D6028;
}
