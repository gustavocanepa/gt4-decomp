typedef unsigned int u32;

extern "C" void mModelSet__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088E150;

extern int D_0088E460;

extern "C" void *mModelSetPS2__tf(void) {
    if (D_0088E460 == 0) {
        mModelSet__tf();
        func_005BFB68(&D_0088E460, ((char *)"12mModelSetPS2"), &D_0088E150);
    }
    return &D_0088E460;
}
