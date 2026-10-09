typedef unsigned int u32;

extern "C" void hValue__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069DBE0[];
extern int D_0088EE90;

extern int D_0088EB20;

extern "C" void *hMethodValue__tf(void) {
    if (D_0088EB20 == 0) {
        hValue__tf();
        func_005BFB68(&D_0088EB20, D_0069DBE0, &D_0088EE90);
    }
    return &D_0088EB20;
}
