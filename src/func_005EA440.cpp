typedef unsigned int u32;

extern "C" void func_005EFF90();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069CE98[];
extern int D_0088EB70;

extern int D_0088E940;

extern "C" void *func_005EA440(void) {
    if (D_0088E940 == 0) {
        func_005EFF90();
        func_005BFB68(&D_0088E940, D_0069CE98, &D_0088EB70);
    }
    return &D_0088E940;
}
