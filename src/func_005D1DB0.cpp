typedef unsigned int u32;

extern "C" void func_005D1BD8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006951A8[];
extern int D_0088DF30;

extern int D_0088DF40;

extern "C" void *func_005D1DB0(void) {
    if (D_0088DF40 == 0) {
        func_005D1BD8();
        func_005BFB68(&D_0088DF40, D_006951A8, &D_0088DF30);
    }
    return &D_0088DF40;
}
