typedef unsigned int u32;

extern "C" void hObject__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00698FE0[];
extern int D_0088EB70;

extern int D_0088E2A0;

extern "C" void *mStorage__tf(void) {
    if (D_0088E2A0 == 0) {
        hObject__tf();
        func_005BFB68(&D_0088E2A0, D_00698FE0, &D_0088EB70);
    }
    return &D_0088E2A0;
}
