typedef unsigned int u32;

extern "C" void func_005EE750();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069E080[];
extern int D_0088EAB0;

extern int D_0088EB80;

extern "C" void *func_005EFFE0(void) {
    if (D_0088EB80 == 0) {
        func_005EE750();
        func_005BFB68(&D_0088EB80, D_0069E080, &D_0088EAB0);
    }
    return &D_0088EB80;
}
