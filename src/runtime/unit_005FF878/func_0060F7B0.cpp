typedef unsigned int u32;

extern "C" void func_0060F770();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006C1038[];
extern int D_006D6218;

extern int D_008A00E0;

extern "C" void *func_0060F7B0(void) {
    if (D_008A00E0 == 0) {
        func_0060F770();
        func_005BFB68(&D_008A00E0, D_006C1038, &D_006D6218);
    }
    return &D_008A00E0;
}
