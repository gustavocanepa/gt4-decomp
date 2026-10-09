typedef unsigned int u32;

extern "C" void HObject__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088DA60;

extern int D_0088DA70;

extern "C" void *MDomNode__tf(void) {
    if (D_0088DA70 == 0) {
        HObject__tf();
        func_005BFB68(&D_0088DA70, ((char *)"8MDomNode"), &D_0088DA60);
    }
    return &D_0088DA70;
}
