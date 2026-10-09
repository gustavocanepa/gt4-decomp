typedef unsigned int u32;

extern "C" void hMethodValue__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088EB20;

extern int D_0088EEF0;

extern "C" void *hBuiltinMethod__tf(void) {
    if (D_0088EEF0 == 0) {
        hMethodValue__tf();
        func_005BFB68(&D_0088EEF0, ((char *)"14hBuiltinMethod"), &D_0088EB20);
    }
    return &D_0088EEF0;
}
