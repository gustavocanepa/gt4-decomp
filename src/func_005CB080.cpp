typedef unsigned int u32;

extern "C" void func_005EFF90();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00690B68[];
extern int D_0088EB70;

extern int D_0088DBE0;

extern "C" void *func_005CB080(void) {
    if (D_0088DBE0 == 0) {
        func_005EFF90();
        func_005BFB68(&D_0088DBE0, D_00690B68, &D_0088EB70);
    }
    return &D_0088DBE0;
}
