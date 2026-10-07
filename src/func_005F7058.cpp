typedef unsigned int u32;

extern "C" void func_005F3968();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A0208[];
extern int D_006D5F68;

extern int D_0088F290;

extern "C" void *func_005F7058(void) {
    if (D_0088F290 == 0) {
        func_005F3968();
        func_005BFB68(&D_0088F290, D_006A0208, &D_006D5F68);
    }
    return &D_0088F290;
}
