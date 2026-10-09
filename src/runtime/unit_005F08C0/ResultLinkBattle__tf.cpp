typedef unsigned int u32;

extern "C" void ResultArcade__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088F8B0;

extern int D_0088F050;

extern "C" void *ResultLinkBattle__tf(void) {
    if (D_0088F050 == 0) {
        ResultArcade__tf();
        func_005BFB68(&D_0088F050, ((char *)"16ResultLinkBattle"), &D_0088F8B0);
    }
    return &D_0088F050;
}
