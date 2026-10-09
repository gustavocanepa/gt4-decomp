typedef unsigned int u32;

extern "C" void PauseBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D6030;

extern int D_0088F790;

extern "C" void *RacePause__tf(void) {
    if (D_0088F790 == 0) {
        PauseBase__tf();
        func_005BFB68(&D_0088F790, ((char *)"9RacePause"), &D_006D6030);
    }
    return &D_0088F790;
}
