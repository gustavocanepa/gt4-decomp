typedef unsigned int u32;

extern "C" void func_005EFF90();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00697168[];
extern int D_0088EB70;

static int D_0088D9A0;

extern "C" void *func_005D4F58(void) {
    if (D_0088D9A0 == 0) {
        func_005EFF90();
        func_005BFB68(&D_0088D9A0, D_00697168, &D_0088EB70);
    }
    return &D_0088D9A0;
}
