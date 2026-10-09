typedef unsigned int u32;

extern "C" void mStorage__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069A5C8[];
extern int D_0088E2A0;

extern int D_0088E490;

extern "C" void *mStorageMC__tf(void) {
    if (D_0088E490 == 0) {
        mStorage__tf();
        func_005BFB68(&D_0088E490, D_0069A5C8, &D_0088E2A0);
    }
    return &D_0088E490;
}
