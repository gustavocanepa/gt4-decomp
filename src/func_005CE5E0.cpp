typedef unsigned int u32;

extern "C" void func_005EFF90();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00693170[];
extern int D_0088EB70;

extern int D_0088DD40;

extern "C" void *func_005CE5E0(void) {
    if (D_0088DD40 == 0) {
        func_005EFF90();
        func_005BFB68(&D_0088DD40, D_00693170, &D_0088EB70);
    }
    return &D_0088DD40;
}
