typedef unsigned int u32;

extern "C" void hVariable__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088EEA0;

extern int D_0088EB00;

extern "C" void *hLocalVariable__tf(void) {
    if (D_0088EB00 == 0) {
        hVariable__tf();
        func_005BFB68(&D_0088EB00, ((char *)"14hLocalVariable"), &D_0088EEA0);
    }
    return &D_0088EB00;
}
