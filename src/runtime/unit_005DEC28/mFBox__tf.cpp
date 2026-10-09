extern "C" void mBox__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069B120[];
extern int D_0088E020;

extern int D_0088E610;

extern "C" void *mFBox__tf(void) {
    if (D_0088E610 == 0) {
        mBox__tf();
        func_005BFB68(&D_0088E610, D_0069B120, &D_0088E020);
    }
    return &D_0088E610;
}
