typedef unsigned int u32;

extern "C" void func_005EFF90();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069D8C8[];
extern int D_0088EB70;

extern int D_0088EAA0;

extern "C" void *func_005EE700(void) {
    if (D_0088EAA0 == 0) {
        func_005EFF90();
        func_005BFB68(&D_0088EAA0, D_0069D8C8, &D_0088EB70);
    }
    return &D_0088EAA0;
}
