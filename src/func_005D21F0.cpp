typedef unsigned int u32;

extern "C" void func_005D0C00();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00695348[];
extern int D_006D5E80;

extern int D_0088DF90;

extern "C" void *func_005D21F0(void) {
    if (D_0088DF90 == 0) {
        func_005D0C00();
        func_005BFB68(&D_0088DF90, D_00695348, &D_006D5E80);
    }
    return &D_0088DF90;
}
