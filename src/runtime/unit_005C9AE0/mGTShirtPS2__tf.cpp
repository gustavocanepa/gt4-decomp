typedef unsigned int u32;

extern "C" void mGTShirt__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088DDC0;

extern int D_0088DE20;

extern "C" void *mGTShirtPS2__tf(void) {
    if (D_0088DE20 == 0) {
        mGTShirt__tf();
        func_005BFB68(&D_0088DE20, ((char *)"11mGTShirtPS2"), &D_0088DDC0);
    }
    return &D_0088DE20;
}
