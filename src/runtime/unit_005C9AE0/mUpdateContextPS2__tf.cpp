typedef unsigned int u32;

extern "C" void mUpdateContext__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00697CD8[];
extern int D_0088E340;

extern int D_0088E110;

extern "C" void *mUpdateContextPS2__tf(void) {
    if (D_0088E110 == 0) {
        mUpdateContext__tf();
        func_005BFB68(&D_0088E110, D_00697CD8, &D_0088E340);
    }
    return &D_0088E110;
}
