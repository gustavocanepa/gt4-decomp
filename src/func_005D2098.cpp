typedef unsigned int u32;

extern "C" void func_005D1E70();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006952A8[];
extern int D_0088DF70;

extern int D_0088DF50;

extern "C" void *func_005D2098(void) {
    if (D_0088DF50 == 0) {
        func_005D1E70();
        func_005BFB68(&D_0088DF50, D_006952A8, &D_0088DF70);
    }
    return &D_0088DF50;
}
