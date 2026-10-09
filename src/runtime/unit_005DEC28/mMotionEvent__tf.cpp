typedef unsigned int u32;

extern "C" void mWindowEvent__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069C448[];
extern int D_0088E400;

extern int D_0088E820;

extern "C" void *mMotionEvent__tf(void) {
    if (D_0088E820 == 0) {
        mWindowEvent__tf();
        func_005BFB68(&D_0088E820, D_0069C448, &D_0088E400);
    }
    return &D_0088E820;
}
