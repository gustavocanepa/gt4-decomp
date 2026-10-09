typedef unsigned int u32;

extern "C" void mImage__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069A4D8[];
extern int D_0088E0D0;

extern int D_0088E450;

extern "C" void *mImagePS2__tf(void) {
    if (D_0088E450 == 0) {
        mImage__tf();
        func_005BFB68(&D_0088E450, D_0069A4D8, &D_0088E0D0);
    }
    return &D_0088E450;
}
