typedef unsigned int u32;

extern "C" void func_005EFE50();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069D740[];
extern int D_0088EB30;

extern int D_0088EA40;

extern "C" void *func_005EDCA0(void) {
    if (D_0088EA40 == 0) {
        func_005EFE50();
        func_005BFB68(&D_0088EA40, D_0069D740, &D_0088EB30);
    }
    return &D_0088EA40;
}
