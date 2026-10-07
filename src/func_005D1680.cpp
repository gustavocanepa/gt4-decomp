typedef unsigned int u32;

extern "C" void func_005D15A8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00694FD0[];
extern int D_0088DEB0;

extern int D_0088DF00;

extern "C" void *func_005D1680(void) {
    if (D_0088DF00 == 0) {
        func_005D15A8();
        func_005BFB68(&D_0088DF00, D_00694FD0, &D_0088DEB0);
    }
    return &D_0088DF00;
}
