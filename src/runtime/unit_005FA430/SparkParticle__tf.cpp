typedef unsigned int u32;

extern "C" void Particle__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D6020;

extern int D_0088F780;

extern "C" void *SparkParticle__tf(void) {
    if (D_0088F780 == 0) {
        Particle__tf();
        func_005BFB68(&D_0088F780, ((char *)"13SparkParticle"), &D_006D6020);
    }
    return &D_0088F780;
}
