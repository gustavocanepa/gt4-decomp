typedef unsigned int u32;

extern "C" void func_005D1680();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00694FF0[];
extern int D_0088DF00;

static int D_0088D9A0;

extern "C" void *func_005D1740(void) {
    if (D_0088D9A0 == 0) {
        func_005D1680();
        func_005BFB68(&D_0088D9A0, D_00694FF0, &D_0088DF00);
    }
    return &D_0088D9A0;
}
