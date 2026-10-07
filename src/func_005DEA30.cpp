typedef unsigned int u32;

extern "C" void func_005EFE50();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069A008[];
extern int D_0088EB30;

extern int D_0088E3B0;

extern "C" void *func_005DEA30(void) {
    if (D_0088E3B0 == 0) {
        func_005EFE50();
        func_005BFB68(&D_0088E3B0, D_0069A008, &D_0088EB30);
    }
    return &D_0088E3B0;
}
