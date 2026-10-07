typedef unsigned int u32;

extern "C" void func_005D8300();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00697650[];
extern int D_0088DA60;

extern int D_0088DA70;

extern "C" void *func_005D82B0(void) {
    if (D_0088DA70 == 0) {
        func_005D8300();
        func_005BFB68(&D_0088DA70, D_00697650, &D_0088DA60);
    }
    return &D_0088DA70;
}
