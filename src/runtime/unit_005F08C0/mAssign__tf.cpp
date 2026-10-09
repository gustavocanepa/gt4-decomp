typedef unsigned int u32;

extern "C" void hInst__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088EAC0;

extern int D_0088ECD0;

extern "C" void *mAssign__tf(void) {
    if (D_0088ECD0 == 0) {
        hInst__tf();
        func_005BFB68(&D_0088ECD0, ((char *)"7mAssign"), &D_0088EAC0);
    }
    return &D_0088ECD0;
}
