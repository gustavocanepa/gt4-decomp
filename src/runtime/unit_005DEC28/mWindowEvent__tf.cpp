typedef unsigned int u32;

extern "C" void mEvent__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069A330[];
extern int D_0088E600;

extern int D_0088E400;

extern "C" void *mWindowEvent__tf(void) {
    if (D_0088E400 == 0) {
        mEvent__tf();
        func_005BFB68(&D_0088E400, D_0069A330, &D_0088E600);
    }
    return &D_0088E400;
}
