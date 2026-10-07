typedef unsigned int u32;

extern "C" void func_005EFF90();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069D5F8[];
extern int D_0088EB70;

extern int D_0088EA00;

extern "C" void *func_005ED8F0(void) {
    if (D_0088EA00 == 0) {
        func_005EFF90();
        func_005BFB68(&D_0088EA00, D_0069D5F8, &D_0088EB70);
    }
    return &D_0088EA00;
}
