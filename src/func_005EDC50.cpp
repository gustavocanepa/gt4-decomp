typedef unsigned int u32;

extern "C" void func_005EFF90();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069D698[];
extern int D_0088EB70;

extern int D_0088EA30;

extern "C" void *func_005EDC50(void) {
    if (D_0088EA30 == 0) {
        func_005EFF90();
        func_005BFB68(&D_0088EA30, D_0069D698, &D_0088EB70);
    }
    return &D_0088EA30;
}
