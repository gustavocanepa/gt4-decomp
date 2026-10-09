typedef unsigned int u32;

extern "C" void mWidget__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0068E7D0[];
extern int D_0088E3B0;

extern int D_0088DAC0;

extern "C" void *mSceneViewFace__tf(void) {
    if (D_0088DAC0 == 0) {
        mWidget__tf();
        func_005BFB68(&D_0088DAC0, D_0068E7D0, &D_0088E3B0);
    }
    return &D_0088DAC0;
}
