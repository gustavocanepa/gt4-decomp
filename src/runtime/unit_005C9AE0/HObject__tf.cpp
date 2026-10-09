typedef unsigned int u32;

extern "C" void RefPointer__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D5E20;

extern int D_0088DA60;

extern "C" void *HObject__tf(void) {
    if (D_0088DA60 == 0) {
        RefPointer__tf();
        func_005BFB68(&D_0088DA60, ((char *)"7HObject"), &D_006D5E20);
    }
    return &D_0088DA60;
}
