typedef unsigned int u32;

extern "C" void hModule__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069A008[];
extern int D_0088EB30;

extern int D_0088E3B0;

extern "C" void *mWidget__tf(void) {
    if (D_0088E3B0 == 0) {
        hModule__tf();
        func_005BFB68(&D_0088E3B0, D_0069A008, &D_0088EB30);
    }
    return &D_0088E3B0;
}
