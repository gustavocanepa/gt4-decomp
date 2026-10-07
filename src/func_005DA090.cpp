typedef unsigned int u32;

extern "C" void func_005DB1D0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00697CC0[];
extern int D_0088E220;

static int D_0088D9A0;

extern "C" void *func_005DA090(void) {
    if (D_0088D9A0 == 0) {
        func_005DB1D0();
        func_005BFB68(&D_0088D9A0, D_00697CC0, &D_0088E220);
    }
    return &D_0088D9A0;
}
