typedef unsigned int u32;

extern "C" void RefCounter__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D5F58;

extern int D_0088E850;

extern "C" void *mOSKeyboard__tf(void) {
    if (D_0088E850 == 0) {
        RefCounter__tf();
        func_005BFB68(&D_0088E850, ((char *)"11mOSKeyboard"), &D_006D5F58);
    }
    return &D_0088E850;
}
