typedef unsigned int u32;

extern "C" void mComposite__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069BD88[];
extern int D_0088E060;

extern int D_0088E780;

extern "C" void *mKeytopBox__tf(void) {
    if (D_0088E780 == 0) {
        mComposite__tf();
        func_005BFB68(&D_0088E780, D_0069BD88, &D_0088E060);
    }
    return &D_0088E780;
}
