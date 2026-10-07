typedef unsigned int u32;

extern "C" void func_005D5828();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00698470[];
extern int D_0088E060;

extern int D_0088E1D0;

extern "C" void *func_005DAD50(void) {
    if (D_0088E1D0 == 0) {
        func_005D5828();
        func_005BFB68(&D_0088E1D0, D_00698470, &D_0088E060);
    }
    return &D_0088E1D0;
}
