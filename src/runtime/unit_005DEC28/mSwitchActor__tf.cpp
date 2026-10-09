typedef unsigned int u32;

extern "C" void mActor__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088E000;

extern int D_0088E970;

extern "C" void *mSwitchActor__tf(void) {
    if (D_0088E970 == 0) {
        mActor__tf();
        func_005BFB68(&D_0088E970, ((char *)"12mSwitchActor"), &D_0088E000);
    }
    return &D_0088E970;
}
