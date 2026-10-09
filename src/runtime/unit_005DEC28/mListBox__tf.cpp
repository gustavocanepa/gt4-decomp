typedef unsigned int u32;

extern "C" void mScrollable__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069C040[];
extern int D_0088E910;

extern int D_0088E7B0;

extern "C" void *mListBox__tf(void) {
    if (D_0088E7B0 == 0) {
        mScrollable__tf();
        func_005BFB68(&D_0088E7B0, D_0069C040, &D_0088E910);
    }
    return &D_0088E7B0;
}
