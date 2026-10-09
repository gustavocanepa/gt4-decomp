typedef unsigned int u32;

extern "C" void hObject__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069A380[];
extern int D_0088EB70;

extern int D_0088E410;

extern "C" void *mXml__tf(void) {
    if (D_0088E410 == 0) {
        hObject__tf();
        func_005BFB68(&D_0088E410, D_0069A380, &D_0088EB70);
    }
    return &D_0088E410;
}
