typedef unsigned int u32;

extern "C" void mWindowEvent__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088E400;

extern int D_0088E510;

extern "C" void *mButtonEvent__tf(void) {
    if (D_0088E510 == 0) {
        mWindowEvent__tf();
        func_005BFB68(&D_0088E510, ((char *)"12mButtonEvent"), &D_0088E400);
    }
    return &D_0088E510;
}
