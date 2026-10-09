typedef unsigned int u32;

extern "C" void hObject__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069CE98[];
extern int D_0088EB70;

extern int D_0088E940;

extern "C" void *mSession__tf(void) {
    if (D_0088E940 == 0) {
        hObject__tf();
        func_005BFB68(&D_0088E940, D_0069CE98, &D_0088EB70);
    }
    return &D_0088E940;
}
