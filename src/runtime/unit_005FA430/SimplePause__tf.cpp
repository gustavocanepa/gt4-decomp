typedef unsigned int u32;

extern "C" void PauseBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D6030;

extern int D_0088F7A0;

extern "C" void *SimplePause__tf(void) {
    if (D_0088F7A0 == 0) {
        PauseBase__tf();
        func_005BFB68(&D_0088F7A0, ((char *)"11SimplePause"), &D_006D6030);
    }
    return &D_0088F7A0;
}
