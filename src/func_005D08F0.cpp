typedef unsigned int u32;

extern "C" void func_005CF248();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00693B88[];
extern int D_0088DD90;

extern int D_0088DE00;

extern "C" void *func_005D08F0(void) {
    if (D_0088DE00 == 0) {
        func_005CF248();
        func_005BFB68(&D_0088DE00, D_00693B88, &D_0088DD90);
    }
    return &D_0088DE00;
}
