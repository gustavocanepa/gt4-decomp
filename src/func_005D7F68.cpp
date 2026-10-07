typedef unsigned int u32;

extern "C" void func_005EFF90();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00697548[];
extern int D_0088EB70;

extern int D_0088E070;

extern "C" void *func_005D7F68(void) {
    if (D_0088E070 == 0) {
        func_005EFF90();
        func_005BFB68(&D_0088E070, D_00697548, &D_0088EB70);
    }
    return &D_0088E070;
}
