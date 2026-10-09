typedef unsigned int u32;

extern "C" void mMovie__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088E170;

extern int D_0088E470;

extern "C" void *mMoviePS2__tf(void) {
    if (D_0088E470 == 0) {
        mMovie__tf();
        func_005BFB68(&D_0088E470, ((char *)"9mMoviePS2"), &D_0088E170);
    }
    return &D_0088E470;
}
