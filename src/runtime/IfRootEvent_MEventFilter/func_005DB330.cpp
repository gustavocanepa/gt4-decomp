typedef unsigned int u32;

extern "C" void mRootWindow__tf();
extern "C" void func_005C0E78(void *a0, void *a1, void *a2);

extern char D_00698830[];
extern int D_0088E240;

extern int D_0088E200;

extern "C" void *func_005DB330(void) {
    if (D_0088E200 == 0) {
        mRootWindow__tf();
        func_005C0E78(&D_0088E200, D_00698830, &D_0088E240);
    }
    return &D_0088E200;
}
