typedef unsigned int u32;

extern "C" void func_005D1E70();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00695288[];
extern int D_0088DF70;

static int D_0088D9A0;

extern "C" void *func_005D1FA0(void) {
    if (D_0088D9A0 == 0) {
        func_005D1E70();
        func_005BFB68(&D_0088D9A0, D_00695288, &D_0088DF70);
    }
    return &D_0088D9A0;
}
