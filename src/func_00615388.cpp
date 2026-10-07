typedef unsigned int u32;

extern "C" void func_00615BD8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006CF880[];
extern int D_006D62F0;

extern int D_008A1C30;

extern "C" void *func_00615388(void) {
    if (D_008A1C30 == 0) {
        func_00615BD8();
        func_005BFB68(&D_008A1C30, D_006CF880, &D_006D62F0);
    }
    return &D_008A1C30;
}
