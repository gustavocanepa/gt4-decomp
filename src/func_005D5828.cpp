typedef unsigned int u32;

extern "C" void func_005DEA30();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00697490[];
extern int D_0088E3B0;

extern int D_0088E060;

extern "C" void *func_005D5828(void) {
    if (D_0088E060 == 0) {
        func_005DEA30();
        func_005BFB68(&D_0088E060, D_00697490, &D_0088E3B0);
    }
    return &D_0088E060;
}
