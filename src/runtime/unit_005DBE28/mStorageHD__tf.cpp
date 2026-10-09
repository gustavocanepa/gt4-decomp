typedef unsigned int u32;

extern "C" void mStorage__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088E2A0;

extern int D_0088E2B0;

extern "C" void *mStorageHD__tf(void) {
    if (D_0088E2B0 == 0) {
        mStorage__tf();
        func_005BFB68(&D_0088E2B0, ((char *)"10mStorageHD"), &D_0088E2A0);
    }
    return &D_0088E2B0;
}
