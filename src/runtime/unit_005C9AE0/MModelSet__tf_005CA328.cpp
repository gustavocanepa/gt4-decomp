typedef unsigned int u32;

extern "C" void MData__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088DB50;

extern int D_0088DB30;

extern "C" void *MModelSet__tf(void) {
    if (D_0088DB30 == 0) {
        MData__tf();
        func_005BFB68(&D_0088DB30, ((char *)"9MModelSet"), &D_0088DB50);
    }
    return &D_0088DB30;
}
