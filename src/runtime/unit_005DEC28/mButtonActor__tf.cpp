typedef unsigned int u32;

extern "C" void mActor__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088E000;

extern int D_0088E500;

extern "C" void *mButtonActor__tf(void) {
    if (D_0088E500 == 0) {
        mActor__tf();
        func_005BFB68(&D_0088E500, ((char *)"12mButtonActor"), &D_0088E000);
    }
    return &D_0088E500;
}
