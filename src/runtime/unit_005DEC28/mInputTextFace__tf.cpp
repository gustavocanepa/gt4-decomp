typedef unsigned int u32;

extern "C" void mWidget__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088E3B0;

extern int D_0088E730;

extern "C" void *mInputTextFace__tf(void) {
    if (D_0088E730 == 0) {
        mWidget__tf();
        func_005BFB68(&D_0088E730, ((char *)"14mInputTextFace"), &D_0088E3B0);
    }
    return &D_0088E730;
}
