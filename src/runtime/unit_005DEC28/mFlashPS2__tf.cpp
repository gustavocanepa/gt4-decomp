typedef unsigned int u32;

extern "C" void mFlash__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069A4A8[];
extern int D_0088E630;

extern int D_0088E440;

extern "C" void *mFlashPS2__tf(void) {
    if (D_0088E440 == 0) {
        mFlash__tf();
        func_005BFB68(&D_0088E440, D_0069A4A8, &D_0088E630);
    }
    return &D_0088E440;
}
