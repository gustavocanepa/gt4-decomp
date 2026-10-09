typedef unsigned int u32;

extern "C" void mEyetoyImageProcessor__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088DDB0;

extern int D_0088DDC0;

extern "C" void *mGTShirt__tf(void) {
    if (D_0088DDC0 == 0) {
        mEyetoyImageProcessor__tf();
        func_005BFB68(&D_0088DDC0, ((char *)"8mGTShirt"), &D_0088DDB0);
    }
    return &D_0088DDC0;
}
