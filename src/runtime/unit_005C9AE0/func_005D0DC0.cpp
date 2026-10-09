typedef unsigned int u32;

extern "C" void func_005C2868();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00693EC0[];
extern int D_0088DA40;

extern int D_0088DE60;

extern "C" void *func_005D0DC0(void) {
    if (D_0088DE60 == 0) {
        func_005C2868();
        func_005BFB68(&D_0088DE60, D_00693EC0, &D_0088DA40);
    }
    return &D_0088DE60;
}
