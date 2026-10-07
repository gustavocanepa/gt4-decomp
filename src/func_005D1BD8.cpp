typedef unsigned int u32;

extern "C" void func_005D1818();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00695168[];
extern int D_0088DE90;

extern int D_0088DF30;

extern "C" void *func_005D1BD8(void) {
    if (D_0088DF30 == 0) {
        func_005D1818();
        func_005BFB68(&D_0088DF30, D_00695168, &D_0088DE90);
    }
    return &D_0088DF30;
}
