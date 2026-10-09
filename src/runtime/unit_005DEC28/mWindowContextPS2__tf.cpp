typedef unsigned int u32;

extern "C" void mWindowContext__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088E3F0;

extern int D_0088E3E0;

extern "C" void *mWindowContextPS2__tf(void) {
    if (D_0088E3E0 == 0) {
        mWindowContext__tf();
        func_005BFB68(&D_0088E3E0, ((char *)"17mWindowContextPS2"), &D_0088E3F0);
    }
    return &D_0088E3E0;
}
