typedef unsigned int u32;

extern "C" void func_0060F508();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D6210;

extern int D_008A0100;

extern "C" void *func_0060F548(void) {
    if (D_008A0100 == 0) {
        func_0060F508();
        func_005BFB68(&D_008A0100, ((char *)"Q27PDICOMM9LocalHost"), &D_006D6210);
    }
    return &D_008A0100;
}
