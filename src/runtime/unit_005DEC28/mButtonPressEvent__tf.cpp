typedef unsigned int u32;

extern "C" void mButtonEvent__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088E510;

extern int D_0088E520;

extern "C" void *mButtonPressEvent__tf(void) {
    if (D_0088E520 == 0) {
        mButtonEvent__tf();
        func_005BFB68(&D_0088E520, ((char *)"17mButtonPressEvent"), &D_0088E510);
    }
    return &D_0088E520;
}
