typedef unsigned int u32;

extern "C" void func_005EFF90();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069DAA0[];
extern int D_0088EB70;

extern int D_0088EAE0;

extern "C" void *func_005EE958(void) {
    if (D_0088EAE0 == 0) {
        func_005EFF90();
        func_005BFB68(&D_0088EAE0, D_0069DAA0, &D_0088EB70);
    }
    return &D_0088EAE0;
}
