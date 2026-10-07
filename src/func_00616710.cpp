typedef unsigned int u32;

extern "C" void func_00616588();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006D3048[];
extern int D_008A20A0;

static int D_0088D9A0;

extern "C" void *func_00616710(void) {
    if (D_0088D9A0 == 0) {
        func_00616588();
        func_005BFB68(&D_0088D9A0, D_006D3048, &D_008A20A0);
    }
    return &D_0088D9A0;
}
