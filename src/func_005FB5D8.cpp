typedef unsigned int u32;

extern "C" void func_005FB518();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A2930[];
extern int D_0088F740;

extern int D_0088F750;

extern "C" void *func_005FB5D8(void) {
    if (D_0088F750 == 0) {
        func_005FB518();
        func_005BFB68(&D_0088F750, D_006A2930, &D_0088F740);
    }
    return &D_0088F750;
}
