typedef unsigned int u32;

extern "C" void mEyetoy__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088DD90;

extern int D_0088DE00;

extern "C" void *mEyetoyPS2__tf(void) {
    if (D_0088DE00 == 0) {
        mEyetoy__tf();
        func_005BFB68(&D_0088DE00, ((char *)"10mEyetoyPS2"), &D_0088DD90);
    }
    return &D_0088DE00;
}
