typedef unsigned int u32;

extern "C" void mBox__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088E020;

extern int D_0088E7F0;

extern "C" void *mMBox__tf(void) {
    if (D_0088E7F0 == 0) {
        mBox__tf();
        func_005BFB68(&D_0088E7F0, ((char *)"5mMBox"), &D_0088E020);
    }
    return &D_0088E7F0;
}
