typedef unsigned int u32;

extern "C" void func_00616588();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006D3060[];
extern int D_008A20A0;

extern int D_008A20C0;

extern "C" void *func_006167E0(void) {
    if (D_008A20C0 == 0) {
        func_00616588();
        func_005BFB68(&D_008A20C0, D_006D3060, &D_008A20A0);
    }
    return &D_008A20C0;
}
