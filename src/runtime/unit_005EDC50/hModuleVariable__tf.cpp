typedef unsigned int u32;

extern "C" void hVariable__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088EEA0;

extern int D_0088EB50;

extern "C" void *hModuleVariable__tf(void) {
    if (D_0088EB50 == 0) {
        hVariable__tf();
        func_005BFB68(&D_0088EB50, ((char *)"15hModuleVariable"), &D_0088EEA0);
    }
    return &D_0088EB50;
}
