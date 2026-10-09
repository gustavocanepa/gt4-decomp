typedef unsigned int u32;

extern "C" void func_0060B780();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_008A0020;

extern int D_0088FF18;

extern "C" void *func_0060A6E8(void) {
    if (D_0088FF18 == 0) {
        func_0060B780();
        func_005BFB68(&D_0088FF18, ((char *)"Q212PlayStation217FileDeviceRo2ExDL"), &D_008A0020);
    }
    return &D_0088FF18;
}
