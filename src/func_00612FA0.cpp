typedef unsigned int u32;

extern "C" void func_00612F10();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006CC5F8[];
extern int D_006D62B0;

extern int D_008A1B70;

extern "C" void *func_00612FA0(void) {
    if (D_008A1B70 == 0) {
        func_00612F10();
        func_005BFB68(&D_008A1B70, D_006CC5F8, &D_006D62B0);
    }
    return &D_008A1B70;
}
