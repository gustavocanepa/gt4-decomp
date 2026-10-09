typedef unsigned int u32;

extern "C" void GTSOUNDINSTRUMENT__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A0300[];
extern int D_006D6118;

extern int D_0088F2B0;

extern "C" void *EngineSound__tf(void) {
    if (D_0088F2B0 == 0) {
        GTSOUNDINSTRUMENT__tf();
        func_005BFB68(&D_0088F2B0, D_006A0300, &D_006D6118);
    }
    return &D_0088F2B0;
}
