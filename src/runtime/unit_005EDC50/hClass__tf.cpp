typedef unsigned int u32;

extern "C" void hModule__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088EB30;

extern int D_0088EA40;

extern "C" void *hClass__tf(void) {
    if (D_0088EA40 == 0) {
        hModule__tf();
        func_005BFB68(&D_0088EA40, ((char *)"6hClass"), &D_0088EB30);
    }
    return &D_0088EA40;
}
