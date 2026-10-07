typedef unsigned int u32;

extern "C" void func_005F1C50();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069DB28[];
extern int D_0088EEA0;

extern int D_0088EB00;

extern "C" void *func_005EEA00(void) {
    if (D_0088EB00 == 0) {
        func_005F1C50();
        func_005BFB68(&D_0088EB00, D_0069DB28, &D_0088EEA0);
    }
    return &D_0088EB00;
}
