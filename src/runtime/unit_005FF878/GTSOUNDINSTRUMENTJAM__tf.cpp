typedef unsigned int u32;

extern "C" void GTSOUNDINSTRUMENT__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D6118;

extern int D_0088FE90;

extern "C" void *GTSOUNDINSTRUMENTJAM__tf(void) {
    if (D_0088FE90 == 0) {
        GTSOUNDINSTRUMENT__tf();
        func_005BFB68(&D_0088FE90, ((char *)"20GTSOUNDINSTRUMENTJAM"), &D_006D6118);
    }
    return &D_0088FE90;
}
